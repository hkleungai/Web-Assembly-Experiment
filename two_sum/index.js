"use strict"

const problem_statement_div = document.getElementById('problem-statement');
const solution_div = document.getElementById('solution');
const test_case_div = document.getElementById('test-case');

document.getElementById('show-problem-statement').onclick = function () {
  test_case_div.style.display = 'none';
  solution_div.style.display = 'none';
  problem_statement_div.style.display = 'block';
}

let src_code;
document.getElementById('show-solution').onclick = async function () {
  if (!src_code)
    src_code = await (await fetch('./Solution.h')).text();

  document.getElementById('solution-src').textContent = src_code;

  problem_statement_div.style.display = 'none';
  test_case_div.style.display = 'none';
  solution_div.style.display = 'block';
}

const ARRAY_ITEM_COUNT_PER_LINE = 10;
let get_test_case;
document.getElementById('generate-test-case').onclick = function () {
  const { input_array, target_sum, ans_array } = get_test_case?.();

  const num_lines = Math.ceil(input_array.length / ARRAY_ITEM_COUNT_PER_LINE);
  let res = Array(num_lines).fill('');
  input_array.forEach(function (a, i) {
    const line_index = Math.floor(i / ARRAY_ITEM_COUNT_PER_LINE);
    if (ans_array.includes(i))
      res[line_index] += `<b class="answer_item">${a}</b>,&emsp;`
    else
      res[line_index] += `${a},&emsp;`
  })

  document.getElementById('input-array').innerHTML = res.join('<br>');
  document.getElementById('target-sum').innerHTML = target_sum;
  document.getElementById('answer').innerHTML = ans_array.join(', ');

  problem_statement_div.style.display = 'none';
  solution_div.style.display = 'none';
  test_case_div.style.display = 'block';
}

import WasmProxy from '../utils/js/WasmProxy.js';

const wasm_source = fetch("main.wasm");
const wasm_imports = new WasmProxy({ env: { js__time: Date.now } });

WebAssembly
  .instantiateStreaming(wasm_source, wasm_imports)
  .then(function (wasm) {
    const {
      memory: { buffer },
      _initialize,
      randomize_input,
      get_input_array,
      get_input_array_size,
      get_target_sum,
      solve,
      get_ans_array,
      get_ans_size,
    } = wasm.instance.exports;

    _initialize();

    get_test_case = function () {
      randomize_input();
      const input_array_size = get_input_array_size();
      const input_array_start = new Uint32Array(buffer, get_input_array(), 1)[0];
      const input_array = new Uint32Array(buffer, input_array_start, input_array_size).slice(0, input_array_size);
      const target_sum = get_target_sum();

      solve();
      const ans_size = get_ans_size();
      const ans_array_start = new Uint32Array(buffer, get_ans_array(), 1)[0];
      const ans_array = new Uint32Array(buffer, ans_array_start, ans_size).slice(0, ans_size);

      return { input_array, target_sum, ans_array };
    }
  });
