#include <cassert>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  int maxSubArray(vector<int> &nums) {
    // FIXME
    return 0;
  }
};

void TestMaxSubArray() {
  Solution s;
  {
    vector<int> numbers{-2, 1, -3, 4, -1, 2, 1, -5, 4};
    assert(6 == s.maxSubArray(nums));
  }
  {
    vector<int> numbers{1};
    assert(1 == s.maxSubArray(nums));
  }
  {
    vector<int> numbers{5, 4, -1, 7, 8};
    assert(23 == s.maxSubArray(nums));
  }
}

int main() {
  TestMaxSubArray();
  std::cout << "Ok!" << std::endl;
  return 0;
}
