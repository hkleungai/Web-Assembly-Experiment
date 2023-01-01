CLANG = /usr/local/opt/llvm/bin/clang++

WARNING = 					\
	-Wall 					\
	-Wextra 				\
	-pedantic

STD = -std=c++17

OPTIMIZATION = -O3

LINKER =					\
	-Wl,--no-entry			\
	-Wl,--export-dynamic	\
	-Wl,--allow-undefined	\
	-Wl,--strip-all 		\
	-Wl,--strip-debug 		\
	-Wl,--lto-O3

ifeq ($(include_wasi_sdk), 1)
	DISABLE =					\
    	-fno-builtin        	\
    	-fvisibility=hidden
	WASI_SYSROOT = --sysroot /usr/local/opt/wasi-sysroot
	_TARGET = --target=wasm32-wasi
	TARGET = $(_TARGET) $(WASI_SYSROOT) $(DISABLE)
else
	DISABLE =					\
		-fno-builtin			\
    	-fvisibility=hidden		\
		-nostdlib
	_TARGET = --target=wasm32
	TARGET = $(_TARGET) $(DISABLE)
endif

ifeq ($(verbose), 1)
	VERBOSE = -v
endif

MODEL = -mexec-model=reactor

MACRO = -DWEB_ENV		\

CLANG_WITH_FLAGS =		\
	$(CLANG)			\
	$(WARNING)			\
	$(STD)				\
	$(TARGET)			\
	$(OPTIMIZATION)		\
	$(LINKER)			\
	$(MODEL)			\
	$(MACRO)
