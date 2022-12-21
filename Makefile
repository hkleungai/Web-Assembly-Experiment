CLANG				= /usr/local/opt/llvm/bin/clang++
WARNING 			= -Wall -Wextra -pedantic
DISABLE 			= -fno-builtin -nostdlib
STD					= -std=c++17
TARGET  			= --target=wasm32
OPTIMIZATION		= -O3
LINKER				= -Wl,--no-entry -Wl,--export-all -Wl,--allow-undefined
FULL_DEMO_TARGET	= src/$(DEMO_TARGET)
DEMO_OUTPUT			= -o $(FULL_DEMO_TARGET)/main.wasm
DEMO_SRC			= $(FULL_DEMO_TARGET)/main.cpp

demo:
	$(shell						\
		$(CLANG)				\
		$(WARNING)   			\
		$(DISABLE)   			\
		$(STD)   				\
		$(TARGET)   			\
		$(OPTIMIZATION)  		\
		$(LINKER)   			\
		$(DEMO_OUTPUT)   		\
		$(DEMO_SRC)   			\
	)