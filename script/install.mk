WASI_SDK_MAJOR_VERSION = 17
WASI_SDK_MINOR_VERSION = 0
WASI_SDK_FULL_VERSION = $(WASI_SDK_MAJOR_VERSION).$(WASI_SDK_MINOR_VERSION)

WASI_SDK_RELEASE_DOMAIN = https://github.com/WebAssembly/wasi-sdk/releases/download/wasi-sdk-$(WASI_SDK_MAJOR_VERSION)

WASK_SDK_SYSROOT_TAR = wasi-sysroot-$(WASI_SDK_FULL_VERSION).tar.gz

# Due to inconsistency btw llvm and wasi-sdk,
# we need this "magic" tar file helps llvm link and compile wasm correctly
# See https://github.com/jedisct1/libclang_rt.builtins-wasm32.a
WASK_SDK_MAGIC_TAR = libclang_rt.builtins-wasm32-wasi-$(WASI_SDK_FULL_VERSION).tar.gz

ifneq ($$EUID, "0")
	SUDO_OR_NORMAL = sudo
else
	SUDO_OR_NORMAL =
endif

install:
    ifndef toolchain
		@echo "Please supply a value for \`toolchain\`."
    else ifeq ($(toolchain), llvm)
		@make install--llvm
    else ifeq ($(toolchain), llvm-wasi)
		@make install--llvm-and-wasi-sdk
    else
		@echo "Unimplemented toolchain. Please run \`make help\` to see for the available options."
    endif

install--binaryen:
	@echo "Installing binaryen..."
	brew install binaryen;
	rm -rf $(shell brew --prefix)/bin/wasm-opt
	@echo "Installation on binaryen DONE"

install--llvm: install--binaryen
	@echo "Installing LLVM..."
	brew install llvm;
	@echo "Installation on LLVM DONE"

install--llvm-and-wasi-sdk: install--llvm
	$(eval LLVM_VERSION := $(shell brew list llvm --versions | sed -e "s/llvm //g"))

	$(eval FULL_CLANG_VERSION := $(shell echo "$(LLVM_VERSION)" | sed -r "s/_[0-9]+//g"))
	$(eval MINOR_CLANG_VERSION := $(shell echo "$(FULL_CLANG_VERSION)" | sed -r "s/.[0-9]+$$//g"))
	$(eval MAJOR_CLANG_VERSION := $(shell echo "$(MINOR_CLANG_VERSION)" | sed -r "s/.[0-9]+$$//g"))

	$(eval BREW_PKG_DIR := $(shell brew --prefix llvm | sed "s/\/llvm//g"))

	@echo "Installing WASI SDK..."
	\
	cd $(BREW_PKG_DIR) \
	&& $(SUDO_OR_NORMAL) wget $(WASI_SDK_RELEASE_DOMAIN)/$(WASK_SDK_SYSROOT_TAR) \
	&& $(SUDO_OR_NORMAL) tar xvf $(WASK_SDK_SYSROOT_TAR)

	@echo "Installing WASI Magic Tar..."
	\
	cd $(BREW_PKG_DIR) \
	&& $(SUDO_OR_NORMAL) wget $(WASI_SDK_RELEASE_DOMAIN)/$(WASK_SDK_MAGIC_TAR) \
	&& ( \
		$(SUDO_OR_NORMAL) tar xvf $(WASK_SDK_MAGIC_TAR) -C ./llvm/lib/clang/$(FULL_CLANG_VERSION) \
		|| $(SUDO_OR_NORMAL) tar xvf $(WASK_SDK_MAGIC_TAR) -C ./llvm/lib/clang/$(MINOR_CLANG_VERSION) \
		|| $(SUDO_OR_NORMAL) tar xvf $(WASK_SDK_MAGIC_TAR) -C ./llvm/lib/clang/$(MAJOR_CLANG_VERSION) \
	)

	@echo "Cleaning up..."
	\
	cd $(BREW_PKG_DIR) \
	&& $(SUDO_OR_NORMAL) rm $(WASK_SDK_SYSROOT_TAR) $(WASK_SDK_MAGIC_TAR)*;

	@echo "Installation on WASI SDK DONE"

install--base64:
	@echo "Installing base64..."
	brew install base64;
	@echo "Installation on base64 DONE"
