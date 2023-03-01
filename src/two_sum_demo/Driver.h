#include <algorithm>
#include <ctime>
#include <vector>

#define __USER_DEFINED__SOLUTION_IMPLEMENTATION
#include "Solution.h"

class Driver {
  Solution s;

public:
  int target_sum;
  const int INPUT_SIZE = 1000;
  std::vector<int> input_array, ans_array;

  Driver();
  void randomize_input();
  void solve();
};

#ifdef __USER_DEFINED__DRIVER_IMPLEMENTATION

#ifdef WEB_ENV
  #define time js__time
  EXTERN unsigned time(void* a);
#endif

// TODO: Implement (Custom) Random Class
bool has_rand_seed = false;
int get_rand_int(int lower, int upper) {
  if (!has_rand_seed) {
    srand(time(nullptr));
    has_rand_seed = true;
  }
  return rand() % (upper - lower + 1) + lower;
}

Driver::Driver(): input_array(vector<int>(INPUT_SIZE)) {};

void Driver::randomize_input() {
  target_sum = get_rand_int(20, 100);
  for (int &val : input_array)
    val = get_rand_int(10, 99);
}

void Driver::solve() {
  ans_array = s.twoSum(input_array, target_sum);
}

#endif

#undef __USER_DEFINED__SOLUTION_IMPLEMENTATION
