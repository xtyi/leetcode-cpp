// 二叉树的层平均值
// 广度优先搜索

#include "common.h"

class Solution {
public:
    vector<double> averageOfLevels(TreeNode* root) {
        vector<double> ans;
        if (root == nullptr) {
            return ans;
        }
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            double sum = 0;
            int sz = q.size();
            for (int i = 0; i < sz; i++) {
                TreeNode* node = q.front();
                q.pop();
                sum += node->val;
                if (node->left != nullptr) {
                    q.push(node->left);
                }
                if (node->right != nullptr) {
                    q.push(node->right);
                }
            }
            ans.push_back(sum / sz);
        }
        return ans;
    }
};

