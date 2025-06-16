// 二叉树的层序遍历
// 广度优先搜索

#include "common.h"

class Solution {
public:
    vector<vector<int>> ret;

    vector<vector<int>> levelOrder(TreeNode* root) {
        bfs(root);
        return ret;
    }

    void bfs(TreeNode* root) {
        if (root == nullptr) {
            return;
        }
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            vector<int> layer;
            int sz = q.size();
            for (int i = 0; i < sz; i++) {
                TreeNode* curr = q.front();
                q.pop();
                layer.push_back(curr->val);
                if (curr->left) {
                    q.push(curr->left);
                }
                if (curr->right) {
                    q.push(curr->right);
                }
            }
            ret.push_back(layer);
        }
    }
};
