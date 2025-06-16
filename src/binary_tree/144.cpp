// 二叉树的前序遍历
// 深度优先搜索

#include "common.h"

class Solution {
public:

    vector<int> ans;

    vector<int> preorderTraversal(TreeNode* root) {
        dfs(root);
        return ans;
    }

    void dfs(TreeNode* root) {
        if (root == nullptr) {
            return;
        }
        ans.push_back(root->val);
        dfs(root->left);
        dfs(root->right);
    }
};
