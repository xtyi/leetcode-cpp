// 求根节点到叶节点数字之和
// 深度优先搜索

#include "common.h"

class Solution {
    int sum = 0;
public:
    int sumNumbers(TreeNode* root) {
        dfs(root, 0);
        return sum;
    }

    void dfs(TreeNode* root, int num) {
        if (root == nullptr) {
            return;
        }
        num = num * 10 + root->val;
        if (root->left == nullptr && root->right == nullptr) {
            sum += num;
        }
        dfs(root->left, num);
        dfs(root->right, num);
        num /= 10;
    }
};
