// 300. 最长递增子序列
// https://leetcode.cn/problems/longest-increasing-subsequence/
// tags: 动态规划

#include "common.h"

// 为什么用动态规划
// 最值问题->可能是动态规划,可能是滑动窗口
// 子序列不连续->不可能是滑动窗口
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> dp(nums.size(), 1);
        for (int i = 0; i < nums.size(); i++) {
            for (int j = 0; j < i; j++) {
                if (nums[i] > nums[j]) {
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }
        }
        return *max_element(dp.begin(), dp.end());
    }
};
