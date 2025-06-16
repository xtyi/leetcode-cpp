// 单值二叉树
// 深度优先搜索

#include "common.h"

class Solution {
private:
    bool _isUnivalTree = true;
    int value;
public:
    bool isUnivalTree(TreeNode* root) {
        value = root->val;
        dfs(root);
        return _isUnivalTree;
    }

    void dfs(TreeNode* root) {
        if (!_isUnivalTree || root == nullptr) {
            return;
        }
        if (root->val != value) {
            _isUnivalTree = false;
            return;
        }
        dfs(root->left);
        dfs(root->right);
    }
};
