// 二叉树的直径
// 深度优先搜索+分解问题

#include "common.h"

class Solution {
public:
    int ans = 0;
    int diameterOfBinaryTree(TreeNode* root) {
        dfs(root);
        return ans;
    }

    int dfs(TreeNode* root) {
        if (root == nullptr) {
            return 0;
        }
        int left = dfs(root->left);
        int right = dfs(root->right);

        int diameter = left + right;
        ans = max(ans, diameter);

        return max(left, right) + 1;
    }

};
