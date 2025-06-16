// 二叉树中的最大路径和
// 深度优先搜索

#include "common.h"

class Solution {
public:

    int ans = INT_MIN;

    int maxPathSum(TreeNode* root) {
        dfs(root);
        return ans;
    }

    int dfs(TreeNode* root) {
        if (root == nullptr) {
            return 0;
        }
        int left = dfs(root->left);
        int right = dfs(root->right);

        left = max(left, 0);
        right = max(right, 0);

        // 更新最大路径和
        ans = max(ans, left + right + root->val);

        // 但返回的是 root 到叶子节点最大的路径
        return max(left, right) + root->val;
    }
};
