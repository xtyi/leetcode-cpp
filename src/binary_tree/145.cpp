// 二叉树的后序遍历
// 深度优先搜索

#include "common.h"

class Solution {
private:
    vector<int> results;

public:
    vector<int> postorderTraversal(TreeNode* root) {
        dfs(root);
        return results;
    }

    void dfs(TreeNode* root) {
        if (root == nullptr) {
            return;
        }
        dfs(root->left);
        dfs(root->right);
        results.push_back(root->val);
    }
};
