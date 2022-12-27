"use strict"; 

import assert from 'assert';
import WasmError from '../WasmError.js';

const e = new WasmError('prop.a');

assert.ok(e instanceof Error, '`e` should be an instance of "Error"');

assert.ok(e instanceof WasmError, '`e` should be an instance of "WasmError"');

assert.equal(e.name, 'Wasm Error', '`e.name` should be \'Wasm Error\'');

assert.equal(e.message, '"prop.a" is not implemented', '`e.name` should be \'"prop.a" is not implemented\'');
