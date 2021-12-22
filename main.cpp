#include <cassert>
#include <iostream>
#include <limits>
#include <vector>

using namespace std;

class Solution {
 public:
  int maxSubArray(vector<int> &nums) {
    int local_max = nums[0];
    int global_max = local_max;
    for (int i = 1; i < nums.size(); ++i) {
      local_max = max(nums[i], nums[i] + local_max);
      global_max = max(global_max, local_max);
    }

    return global_max;
  }
};

void TestMaxSubArray() {
  Solution s;

  {
    vector<int> numbers{-1};
    assert(-1 == s.maxSubArray(numbers));
  }
  {
    vector<int> numbers{-2, 1, -3, 4, -1, 2, 1, -5, 4};
    assert(6 == s.maxSubArray(numbers));
  }
  {
    vector<int> numbers{1};
    assert(1 == s.maxSubArray(numbers));
  }
  {
    vector<int> numbers{5, 4, -1, 7, 8};
    assert(23 == s.maxSubArray(numbers));
  }
  {
    vector<int> numbers{-1, 1, 2, 1};
    assert(4 == s.maxSubArray(numbers));
  }
  {
    vector<int> numbers{44, 44, -100, 45};
    assert(88 == s.maxSubArray(numbers));
  }
}

int main() {
  TestMaxSubArray();
  std::cout << "Ok!" << std::endl;
  return 0;
}
