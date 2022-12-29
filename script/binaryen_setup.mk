WASM_OPT = /usr/local/opt/binaryen/bin/wasm-opt

OPTIMIZATION = -O3

ENABLE = --enable-bulk-memory

WASM_OPT_WITH_FLAGS = 	\
	$(WASM_OPT)			\
	$(OPTIMIZATION)		\
	$(ENABLE)
