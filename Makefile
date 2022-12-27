include script/install.mk
include script/clang_setup.mk

FULL_DEMO_TARGET = src/$(demo_target)
DEMO_OUTPUT = -o $(FULL_DEMO_TARGET)/main.wasm
DEMO_SRC = $(FULL_DEMO_TARGET)/main.cpp

demo:
	$(shell					\
		$(CLANG_WITH_FLAGS)	\
		$(DEMO_OUTPUT)		\
		$(DEMO_SRC)			\
		$(VERBOSE)			\
	)

clean:
	rm $(DEMO_OUTPUT)

clean-all:
	rm src/**/*.wasm
