// 53. 最大子数组和
// https://leetcode.cn/problems/maximum-subarray/
// tags: 动态规划

#include "common.h"
#include <algorithm>

// 为什么不用滑动窗口? 没有明显的满足或不满足窗口的条件
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        vector<int> dp(nums.size());
        dp[0] = nums[0];


        for (int i = 1; i < nums.size(); i++) {
            if(dp[i-1] > 0) {
                dp[i] = dp[i-1] + nums[i];
            } else {
                dp[i] = nums[i];
            }
        }

        return *max_element(dp.begin(), dp.end());
    }
};
