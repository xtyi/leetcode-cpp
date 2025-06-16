// 平衡二叉树
// 分解问题+DFS

#include "common.h"

class Solution {
private:
    bool isBalancedTree = true;
public:
    bool isBalanced(TreeNode* root) {
        dfs(root);
        return isBalancedTree;
    }

    int dfs(TreeNode* root) {
        if (root == nullptr || isBalancedTree == false) {
            return 0;
        }
        int leftHeight = dfs(root->left);
        int rightHeight = dfs(root->right);
        if (abs(leftHeight - rightHeight) > 1) {
            isBalancedTree = false;
        }
        return max(leftHeight, rightHeight) + 1;
    }
};
