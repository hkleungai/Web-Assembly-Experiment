"use strict";

import assert from 'assert';
import util from 'util';

import WasmProxy from '../WasmProxy.js';

const target = {
  __virtual_value: 1,
  get node() {
    const self = this;
    return {
      get nested() {
        return self.__virtual_value;
      },
    }
  }
};
const proxy = new WasmProxy(target);

assert.ok(
  util.types.isProxy(proxy),
  'should construct Proxy at given target'
);

assert.deepEqual(
  target.node, proxy.node,
  'should copy target attribute to `proxy`'
);
assert.ok(
  target.node.nested === proxy.node.nested,
  'should copy nested target attribute to `proxy`'
);

const non_exist_node = proxy.non_exist_node;
assert.ok(
  util.types.isProxy(non_exist_node),
  'should construct Proxy at non-exist node'
);
assert(
  non_exist_node === proxy.non_exist_node,
  'should not reconstruct proxy at non-exist node',
);
assert.throws(
  non_exist_node,
  { name: 'Wasm Error', message: '"proxy.non_exist_node()" is not implemented' },
);
assert.throws(
  () => non_exist_node(1,2,3),
  { name: 'Wasm Error', message: '"proxy.non_exist_node(1, 2, 3)" is not implemented' },
);

const non_exist_nested_node = proxy.non_exist_node.non_exist_nested_node;
assert.ok(
  util.types.isProxy(non_exist_nested_node),
  'should construct Proxy at non-exist nested node'
);
assert.ok(
  non_exist_nested_node === proxy.non_exist_node.non_exist_nested_node,
  'should not reconstruct proxy at non-exist nested node',
);
assert.throws(
  non_exist_nested_node,
  { name: 'Wasm Error', message: '"proxy.non_exist_node.non_exist_nested_node()" is not implemented' },
);
assert.throws(
  () => non_exist_nested_node(12,    30),
  { name: 'Wasm Error', message: '"proxy.non_exist_node.non_exist_nested_node(12, 30)" is not implemented' },
);
