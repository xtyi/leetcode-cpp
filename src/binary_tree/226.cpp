// 翻转二叉树
// 分解问题

#include "common.h"

class Solution
{
public:
    TreeNode *invertTree(TreeNode *root)
    {
        if (root == nullptr) {
            return nullptr;
        }
        TreeNode* left = invertTree(root->left);
        TreeNode* right = invertTree(root->right);
        root->left = right;
        root->right = left;
        return root;
    }
};

