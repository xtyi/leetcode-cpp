// 二叉树展开为链表
// 分解问题

#include "common.h"

class Solution {
public:
    void flatten(TreeNode* root) {
        if (root == nullptr) {
            return;
        }
        flatten(root->left);
        flatten(root->right);
        TreeNode *left = root->left;
        TreeNode *right = root->right;
        root->left = nullptr;
        root->right = left;
        TreeNode *p = root;
        while (p->right != nullptr) {
            p = p->right;
        }
        p->right = right;
    }
};
