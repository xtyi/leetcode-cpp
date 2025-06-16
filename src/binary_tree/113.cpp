// 路径总和 II
// 深度优先搜索

#include "common.h"

class Solution {
public:

    vector<vector<int>> ret;
    vector<int> path;

    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        dfs(root, targetSum);
        return ret;
    }

    void dfs(TreeNode* root, int targetSum) {
        if (root == nullptr) {
            return;
        }

        path.push_back(root->val);

        if (root->left == nullptr && root->right == nullptr) {
            if (targetSum == root->val) {
                ret.push_back(path);
            }
        }

        dfs(root->left, targetSum - root->val);
        dfs(root->right, targetSum - root->val);
        path.pop_back();
    }
};


