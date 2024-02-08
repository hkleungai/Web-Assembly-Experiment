"use strict";

export default class WasmError extends Error {
  constructor(paths, args) {
    super(`"proxy.${paths.join('.')}(${args.join(', ')})" is not implemented`);
    this.name = 'Wasm Error';
  }
}
