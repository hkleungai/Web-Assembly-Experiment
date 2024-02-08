"use strict";

import WasmError from './WasmError.js';

export default class WasmProxy {
  constructor(target = {}, paths = []) {
    return new Proxy(target, {
      get(self, key) {
        if (self[key] && typeof self[key] !== 'object') {
          return self[key];
        }
        const new_paths = [...paths, key];
        const new_target = self[key] || ((...args) => { throw new WasmError(new_paths, args) });
        Reflect.set(self, key, new WasmProxy(new_target, new_paths));
        return self[key];
      },
    });
  }
};
