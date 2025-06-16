// 二叉搜索树中第K小的元素
// 深度优先搜索

#include "common.h"

class Solution {

    vector<int> vals;

public:
    int kthSmallest(TreeNode* root, int k) {
        dfs(root);
        return vals[k - 1];
    }

    void dfs(TreeNode* root) {
        if (root == nullptr) {
            return;
        }
        dfs(root->left);
        vals.push_back(root->val);
        dfs(root->right);
    }
};
