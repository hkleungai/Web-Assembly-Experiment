"use strict";

import WasmError from './WasmError.js';

export default class WasmProxy {
  static get validator() {
    function make_validator(...path) {
      return {
        get(self, key) {
          /* If self[key] points to primitive value, return it directly. */
          const is_object = typeof self[key] === 'object' && self[key] !== null;
          if (self[key] && !is_object)
            return self[key];
          
            /* Else construct new "_self" and "_validator" and wrap them with Proxy */
          const _self = is_object ? self[key] : function () { throw new WasmError([...path, key].join('.')) };
          const _validator = make_validator(...path, key);
          const proxy = new Proxy(_self, _validator);
          
          /* Avoid re-creating function() over and over upon accessing proxy's properties */
          Reflect.set(self, key, proxy);

          return proxy;
        },
      }
    }
    return make_validator();
  };
  
  constructor(target = {}) {
    return new Proxy(target, WasmProxy.validator);
  }
};