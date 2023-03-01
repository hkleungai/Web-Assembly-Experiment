WASI_SDK_MAJOR_VERSION = 19
WASI_SDK_MINOR_VERSION = 0
WASI_SDK_FULL_VERSION = $(WASI_SDK_MAJOR_VERSION).$(WASI_SDK_MINOR_VERSION)

WASI_SDK_RELEASE_DOMAIN = https://github.com/WebAssembly/wasi-sdk/releases/download/wasi-sdk-$(WASI_SDK_MAJOR_VERSION)

WASK_SDK_SYSROOT_TAR = wasi-sysroot-$(WASI_SDK_FULL_VERSION).tar.gz

# Due to inconsistency btw llvm and wasi-sdk,
# we need this "magic" tar file helps llvm link and compile wasm correctly
# See https://github.com/jedisct1/libclang_rt.builtins-wasm32.a
WASK_SDK_MAGIC_TAR = libclang_rt.builtins-wasm32-wasi-$(WASI_SDK_FULL_VERSION).tar.gz

install--binaryen:
	@echo "Installing binaryen..."
	brew install binaryen;
	rm -rf /usr/local/bin/wasm*
	@echo "Installation on binaryen DONE"

install--llvm: install--binaryen
	@echo "Installing LLVM..."
	brew install llvm;
	@echo "Installation on LLVM DONE"

install--llvm-and-wasi-sdk: install--llvm
	$(eval LLVM_VERSION := $(shell brew list llvm --versions | sed -e "s/llvm //g"))
	$(eval CLANG_VERSION := $(shell echo "$(LLVM_VERSION)" | sed -r "s/_[0-9]+//g"))

	@echo "Installing WASI SDK..."
	\
	cd /usr/local/opt/ \
	&& wget $(WASI_SDK_RELEASE_DOMAIN)/$(WASK_SDK_SYSROOT_TAR) \
	&& tar xvf $(WASK_SDK_SYSROOT_TAR)

	@echo "Installing WASI Magic Tar..."
	\
  	cd /usr/local/opt/ \
	&& wget $(WASI_SDK_RELEASE_DOMAIN)/$(WASK_SDK_MAGIC_TAR) \
	&& tar xvf $(WASK_SDK_MAGIC_TAR) -C ./llvm/lib/clang/$(CLANG_VERSION)

	@echo "Cleaning up..."
	\
	cd /usr/local/opt/ \
	&& rm $(WASK_SDK_SYSROOT_TAR)* $(WASK_SDK_MAGIC_TAR)*;

	@echo "Installation on WASI SDK DONE"
