"use strict";

import WasmError from './WasmError.js';

export default class WasmProxy {
  static get validator() {
    function make_validator(...path) {
      return {
        get(self, key) {
          const has_key = self.hasOwnProperty(key);
          const is_object = typeof self[key] === 'object' && self[key] !== null;
          /* If self[key] points to primitive value, return it directly. */
          if (has_key && !is_object)
            return self[key];
          /* Else construct new "_self" and "_validator" and wrap them with Proxy */
          const _self = is_object ? self[key] : function () { throw new WasmError([...path, key].join('.')) };
          const _validator = make_validator(...path, key);
          self[key] = new Proxy(_self, _validator);
          return self[key];
        },
      }
    }
    return make_validator();
  };
  
  constructor(target = {}) {
    return new Proxy(target, WasmProxy.validator);
  }
};