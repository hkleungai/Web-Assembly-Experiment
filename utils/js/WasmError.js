"use strict";

export default class WasmError extends Error {
  constructor(path) {
    super(`"${path}" is not implemented`);
    this.name = 'Wasm Error';
  }
}