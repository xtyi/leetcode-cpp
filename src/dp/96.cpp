// 96. 不同的二叉搜索树
// https://leetcode.cn/problems/unique-binary-search-trees/
// tags: 动态规划

#include "common.h"


class Solution {
public:
    int numTrees(int n) {
        vector<int> dp(n+1);
        dp[0] = 1;
        dp[1] = 1;

        for (int i = 2; i < n + 1; i++) {
            for (int j = 1; j <= i; j++) {
                dp[i] += dp[j-1] * dp[i-j];
            }
        }

        return dp[n];
    }
};

