# Introduction

Not sure if I want to fill this yet.

# Compilation

Install necessary packages via brew
```sh
brew install make llvm
```

Create the assembly files for various demo.
Right now "array_demo" is the only available demo_target.
```sh
make demo DEMO_TARGET=<demo_target>
```

Expose `src` to local server. Open `http://localhost:8080` to view the site.
