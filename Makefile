include script/install.mk
include script/binaryen_setup.mk
include script/clang_setup.mk

%.wasm:
	$(CLANG_WITH_FLAGS) -o $@ $*.cpp $(VERBOSE);
	$(WASM_OPT_WITH_FLAGS) -o $@ $@;

help:
	@echo "Build wasm binary from a single C++ file."
	@echo ""
	@echo "HELP MODE    -- make help"
	@echo "    help                 Print this message."
	@echo ""
	@echo "INSTALL MODE -- make install toolchain=\"<toolchain>\""
	@echo "    toolchain            Required."
	@echo "                         Supported options are \`llvm\` and \`llvm-wasi\`."
	@echo ""
	@echo "BUILD MODE   -- make <target>.wasm [include-wasi-sdk=1] [verbose=1]"
	@echo "    <target>.wasm        Required."
	@echo "                         To build \`src/foo/bar.cpp\`, do \`make src/foo/bar.wasm\`."
	@echo "    include-wasi-sdk     Optional."
	@echo "                         If set to 1, WASI SDK Polyfill will be applied."
	@echo "    verbose              Optional."
	@echo "                         If set to 1, execution detail will be shown in terminal."

clean:
	rm src/**/*.wasm
