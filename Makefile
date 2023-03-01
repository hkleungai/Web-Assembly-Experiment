include script/install.mk
include script/binaryen_setup.mk
include script/clang_setup.mk

FULL_DEMO_TARGET = src/$(demo_target)
DEMO_OUTPUT = $(FULL_DEMO_TARGET)/main.wasm
DEMO_SRC = $(FULL_DEMO_TARGET)/main.cpp
UTIL_INCLUDE = src/utils/c

demo:
	$(shell					\
		$(CLANG_WITH_FLAGS)	\
		-I ${UTIL_INCLUDE}  \
		-o $(DEMO_OUTPUT)	\
		$(DEMO_SRC)			\
		$(VERBOSE)			\
	)
	$(shell						\
		$(WASM_OPT_WITH_FLAGS)	\
		-o $(DEMO_OUTPUT)		\
		$(DEMO_OUTPUT)			\
	)

.PHONY: clean clean-all

clean:
	rm $(DEMO_OUTPUT)

clean-all:
	rm src/**/*.wasm
