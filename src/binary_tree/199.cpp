// 二叉树的右视图
// 广度优先搜索

#include "common.h"

class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;
        if (root == nullptr) {
            return ans;
        }
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            vector<int> tmp;
            int sz = q.size();
            for (int i = 0; i < sz; i++) {
                TreeNode* node = q.front();
                q.pop();
                tmp.push_back(node->val);
                if (node->left != nullptr) {
                    q.push(node->left);
                }
                if (node->right != nullptr) {
                    q.push(node->right);
                }
            }
            ans.push_back(tmp.back());
        }
        return ans;
    }
};
