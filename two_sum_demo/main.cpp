#include <algorithm>
#include <ctime>
#include <vector>

#include "../utils/c/extern.h"

#define __USER_DEFINED__DRIVER_IMPLEMENTATION
#include "Driver.h"

Driver driver;

EXTERN void randomize_input() {
  driver.randomize_input();
}

EXTERN std::vector<int>* get_input_array() {
  return &driver.input_array;
}

EXTERN int get_input_array_size() {
  return driver.INPUT_SIZE;
}

EXTERN int get_target_sum() {
  return driver.target_sum;
}

EXTERN void solve() {
  driver.solve();
}

EXTERN std::vector<int>* get_ans_array() {
  return &driver.ans_array;
}

EXTERN int get_ans_size() {
  return 2;
}
