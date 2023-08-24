/**
https://leetcode.com/problems/range-sum-query-immutable/

Given an integer array nums, handle multiple queries of the following type:

Calculate the sum of the elements of nums between indices left and right
inclusive where left <= right. Implement the NumArray class:

NumArray(int[] nums) Initializes the object with the integer array nums.
int sumRange(int left, int right) Returns the sum of the elements of nums
between indices left and right inclusive (i.e. nums[left] + nums[left + 1] + ...
+ nums[right]).


Example 1:

Input
["NumArray", "sumRange", "sumRange", "sumRange"]
[[[-2, 0, 3, -5, 2, -1]], [0, 2], [2, 5], [0, 5]]
Output
[null, 1, -1, -3]

Explanation
NumArray numArray = new NumArray([-2, 0, 3, -5, 2, -1]);
numArray.sumRange(0, 2); // return (-2) + 0 + 3 = 1
numArray.sumRange(2, 5); // return 3 + (-5) + 2 + (-1) = -1
numArray.sumRange(0, 5); // return (-2) + 0 + 3 + (-5) + 2 + (-1) = -3


Constraints:

1 <= nums.length <= 104
-105 <= nums[i] <= 105
0 <= left <= right < nums.length
At most 10^4 calls will be made to sumRange


idea: simple prefix-sufix task
time: O(n)
space: O(n)

**/

#include <iostream>
#include <vector>

using namespace std;

class NumArray {
public:
  NumArray(vector<int> &nums) {
    int size = nums.size();
    prefixes_.resize(size + 1);
    prefixes_[0] = 0;

    for (size_t i = 1; i <= nums.size(); ++i) {
      prefixes_[i] = prefixes_[i - 1] + nums[i - 1];
      std::cout << prefixes_[i] << " ";
    }
    std::cout << "\n";
  }

  int sumRange(int left, int right) {
    return prefixes_[right + 1] - prefixes_[left];
  }

private:
  vector<int> prefixes_;
};
