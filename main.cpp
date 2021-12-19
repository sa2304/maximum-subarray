#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  int maxSubArray(vector<int> &nums) {
    auto start = max_element(nums.begin(), nums.end());
    if (nums.end() != start) {
      auto iter_right = start;
      int sum_right = _walk(iter_right, nums.end());

      auto pos = distance(nums.begin(), start);
      auto rev_start = nums.rbegin() + nums.size() - pos - 1;
      int sum_left = _walk(rev_start, nums.rend());

      return std::max(sum_left, sum_right);
    }

    return 0;
  }

 private:
  template<class Iter>
  int _walk(Iter &first, Iter end) {
    int sum = 0;
    if (first != end) {
      sum = *first++;
      int increment = 0;
      while (first != end) {
        increment += *first++;
        if (0 < increment) {
          sum += increment;
          increment = 0;
        }
      }
    }

    return sum;
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
}

int main() {
  TestMaxSubArray();
  std::cout << "Ok!" << std::endl;
  return 0;
}
