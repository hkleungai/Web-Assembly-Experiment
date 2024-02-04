# Web Assembly (WASM) with C

## Introduction

This is a small experiment / playground for my C-style WASM learning.

**Due to project nature, the web frontend scripts is probably never gonna be optimized nor made ready for production**  😂😂😂😂

## Compilation

This project runs with [GNU Make] in Mac. 

```sh
brew install make
```

Install toolchain.

```sh
make install toolchain="<toolchain>"
```

Compile C++ source file to wasm.

```sh
make src/foo/bar.wasm
```

Expose `src` to local server. Open `http://localhost:8080` to view the site.

For more details, run the help command.

```sh
make help
```

## Remarks

### OS

This project is developed in a Mac machine.
Compilation on other operating systems is not guaranteed to work.

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
