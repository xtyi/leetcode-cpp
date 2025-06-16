// 路径总和 III
// 深度优先搜索

#include "common.h"

class Solution {
public:
    int pathSum(TreeNode* root, int targetSum) {
        if (root == nullptr) {
            return 0;
        }
        int ans = dfs(root, targetSum);
        ans += pathSum(root->left, targetSum);
        ans += pathSum(root->right, targetSum);
        return ans;
    }

    int dfs(TreeNode* root, long long sum) {
        if (root == nullptr) {
            return 0;
        }
        sum -= root->val;
        int ans = 0;
        if (sum == 0) {
            ans++;
        }
        ans += dfs(root->left, sum);
        ans += dfs(root->right, sum);
        return ans;
    }
};
