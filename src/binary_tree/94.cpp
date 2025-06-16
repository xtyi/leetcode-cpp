// 二叉树的中序遍历
// 深度优先搜索

#include "common.h"

class Solution {
    vector<int> ans;
public:
    vector<int> inorderTraversal(TreeNode* root) {
        dfs(root);
        return ans;
    }

    void dfs(TreeNode* root) {
        if (root == nullptr) {
            return;
        }
        dfs(root->left);
        ans.push_back(root->val);
        dfs(root->right);
    }
};
