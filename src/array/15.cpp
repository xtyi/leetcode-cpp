// 15. 三数之和
// https://leetcode.cn/problems/3sum/
// tags: 数组
// tips: 双指针

#include "common.h"

// 不要求返回下标, 可以使用双指针
class Solution {
public:
  vector<vector<int>> threeSum(vector<int> &nums) {
    // 数组得排个序
    sort(nums.begin(), nums.end());
    int n = nums.size();
    vector<vector<int>> res;
    // 穷举 threeSum 的第一个数
    for (int i = 0; i < n; i++) {
      // 对 target - nums[i] 计算 twoSum
      vector<vector<int>> tuples = twoSumTarget(nums, i + 1, -nums[i]);
      // 如果存在满足条件的二元组，再加上 nums[i] 就是结果三元组
      for (vector<int> &tuple : tuples) {
        tuple.push_back(nums[i]);
        res.push_back(tuple);
      }
      // 跳过第一个数字重复的情况，否则会出现重复结果
      while (i < n - 1 && nums[i] == nums[i + 1])
        i++;
    }
    return res;
  }

  vector<vector<int>> twoSumTarget(vector<int> &nums, int start, int target) {
    vector<vector<int>> res;
    int lo = start, hi = nums.size() - 1;
    while (lo < hi) {
      int left = nums[lo], right = nums[hi];
      int sum = left + right;
      // 根据 sum 和 target 的比较，移动左右指针
      if (sum < target) {
        while (lo < hi && nums[lo] == left)
          lo++;
      } else if (sum > target) {
        while (lo < hi && nums[hi] == right)
          hi--;
      } else {
        res.push_back({left, right});
        while (lo < hi && nums[lo] == left)
          lo++;
        while (lo < hi && nums[hi] == right)
          hi--;
      }
    }
    return res;
  }
};
