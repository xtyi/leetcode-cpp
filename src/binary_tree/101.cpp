// 对称二叉树
// 分解问题

#include "common.h"

class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        return check(root, root);
    }

    bool check(TreeNode* left, TreeNode* right) {
        if (left == nullptr && right == nullptr) {
            return true;
        }
        if (left == nullptr || right == nullptr) {
            return false;
        }
        if (left->val != right->val) {
            return false;
        }
        return check(left->left, right->right) && check(left->right, right->left);
    }
};
