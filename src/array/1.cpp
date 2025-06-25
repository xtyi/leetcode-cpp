// 1. 两数之和
// https://leetcode.cn/problems/two-sum/
// tags: 数组
// tips: 哈希表

#include "common.h"

// 不能使用双指针, 因为这里要返回下标, 而双指针需要有序数组, 排序会打乱下标
class Solution {
public:
    std::vector<int> twoSum(std::vector<int>& nums, int target) {
        std::unordered_map<int, int> map;
        for (int i = 0; i < nums.size(); i++) {
            int complement = target - nums[i];
            if (map.count(complement)) {
                return {map[complement], i};
            }
            map[nums[i]] = i;
        }
        return {};
    }
};



int main() {
  Solution solution;
  std::vector<int> nums = {2, 7, 11, 15};
  int target = 9;

  std::vector<int> result = solution.twoSum(nums, target);
  std::cout << "Input: nums = ";
  printVector(nums);
  std::cout << "target = " << target << std::endl;
  std::cout << "Output: ";
  printVector(result);

  return 0;
}
