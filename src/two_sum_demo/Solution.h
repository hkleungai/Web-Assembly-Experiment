#ifndef __USER_DEFINED__SOLUTION_HEADER
#define __USER_DEFINED__SOLUTION_HEADER

#include <map>
#include <vector>

class Solution {
public:
  std::vector<int> twoSum(std::vector<int> &nums, int sum);
};

#endif

/** SEPARATE--HEADER--AND--IMPLEMENTATION */

#ifdef __USER_DEFINED__SOLUTION_IMPLEMENTATION

using namespace std;

vector<int> Solution::twoSum(vector<int>& nums, int sum) {
  map<int, int> memo;
  int nums_size = (int)nums.size();
  for (int i = 0; i < nums_size; i++)
    memo[sum - nums[i]] = i;
  for (int i = 0; i < nums_size; i++) {
    map<int, int>::iterator it = memo.find(nums[i]);
    if (it != memo.end() && i != it->second)
      return { i, it->second };
  }
  return vector<int>();
}
#endif
