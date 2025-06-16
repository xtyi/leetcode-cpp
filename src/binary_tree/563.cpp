// 二叉树的坡度
// 深度优先搜索+分解问题

#include "common.h"

class Solution {
private:
    int result;
public:
    int findTilt(TreeNode* root) {
        dfs(root);
        return result;
    }

    // void dfs(TreeNode* root) {
    //     if (root == nullptr) {
    //         return;
    //     }
    //     int leftValue = getTreeValue(root->left);
    //     int rightValue = getTreeValue(root->right);
    //     result += abs(leftValue - rightValue);
    //     dfs(root->left);
    //     dfs(root->right);
    // }

    // int getTreeValue(TreeNode* root) {
    //     if (root == nullptr) {
    //         return 0;
    //     }
    //     int value = root->val;
    //     value += getTreeValue(root->left);
    //     value += getTreeValue(root->right);
    //     return value;
    // }

    // 以上两个函数可以合并为以下一个函数
    int dfs(TreeNode* root) {
        if (root == nullptr) {
            return 0;
        }
        int leftValue = dfs(root->left);
        int rightValue = dfs(root->right);
        result += abs(leftValue - rightValue);
        return leftValue + rightValue + root->val;
    }
};
