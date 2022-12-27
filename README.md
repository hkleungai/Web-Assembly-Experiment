# Introduction

This is a small experiment / playground for my C-style WASM learning.

**Due to project nature, the web frontend scripts is probably never gonna be optimized nor made ready for production**  😂😂😂😂

# Compilation

This project runs with [GNU Make].
In Mac OS, you may simply do,
```sh
brew install make
```

The suggested beginning tool is [LLVM], which can be installed with 
```bassh
make install--llvm
```

For demo project involving C/C++ library, 
you may also want to include [WASI SDK] support,
```sh
make install--llvm-and-wasi-sdk
```

Create the assembly files for various demo.
Right now "array_demo" is the only available demo_target.
```sh
# Compile with conventional LLVM
make demo DEMO_TARGET=...
# Compile with verbose flag
make demo DEMO_TARGET=... VERBOSE=1
# Compile with LLVM and WASK SDK tool
make demo DEMO_TARGET=... include_wasi_sdk=1
```

Expose `src` to local server. Open `http://localhost:8080` to view the site.

# Remarks

### Compilation Tool Alternatives

As of 2022, `zig` seems to be a more promising way to build WASM from C/C++ source code. 
See its [official github page][Zig Github] and [this post][Zig CC Intro].

However, it still faces certain [issues][Zig CC Issues] that have not yet be overcomed. 
And for now, substituting zig with my current LLVM-based build system seems not the best option.

Anyhow, the exciting development of zig is still worth to be closely monitored. 👀 👀

[GNU Make]: https://www.gnu.org/software/make/
[LLVM]: https://llvm.org
[WASI SDK]: https://github.com/WebAssembly/wasi-sdk
[Zig Github]: https://github.com/ziglang/zig
[Zig CC Intro]: https://andrewkelley.me/post/zig-cc-powerful-drop-in-replacement-gcc-clang.html
[Zig CC Issues]: https://github.com/ziglang/zig/issues?q=zig+cc