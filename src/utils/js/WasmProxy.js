"use strict";

import WasmError from './WasmError.js';

export default class WasmProxy {
  constructor(target = {}, paths = []) {
    return new Proxy(target, {
      get(self, key) {
        const new_paths = [...paths, key];
        if (self[key] === undefined || self[key] === null) {
          const new_target = (...args) => { throw new WasmError(new_paths, args) };
          Reflect.set(self, key, new WasmProxy(new_target, new_paths));
        }
        if (typeof self[key] === 'object') {
          Reflect.set(self, key, new WasmProxy(self[key], new_paths));
        }
        return self[key];
      },
    });
  }
};
