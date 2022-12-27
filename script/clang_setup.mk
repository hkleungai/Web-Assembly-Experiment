CLANG = /usr/local/opt/llvm/bin/clang++

WARNING = 					\
	-Wall 					\
	-Wextra 				\
	-pedantic

STD = -std=c++17

OPTIMIZATION = -O3

LINKER =					\
	-Wl,--no-entry			\
	-Wl,--export-all		\
	-Wl,--allow-undefined

ifeq ($(include_wasi_sdk), 1)
	WASI_SYSROOT = --sysroot /usr/local/opt/wasi-sysroot
	_TARGET = --target=wasm32-wasi
	TARGET = $(_TARGET) $(WASI_SYSROOT)
else
	DISABLE = 				\
		-fno-builtin		\
		-nostdlib
	_TARGET = --target=wasm32
	TARGET = $(_TARGET) $(DISABLE)
endif

ifeq ($(verbose), 1)
	VERBOSE = -v
endif

CLANG_WITH_FLAGS = 		\
	$(CLANG)			\
	$(WARNING)			\
	$(STD)				\
	$(TARGET)			\
	$(OPTIMIZATION)		\
	$(LINKER)			\
