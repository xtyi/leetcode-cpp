// 验证二叉搜索树
// 深度优先搜索

#include "common.h"

class Solution {
public:
    bool isValidBST(TreeNode* root) {
        return check(root, LLONG_MIN, LLONG_MAX);
    }

    bool check(TreeNode* root, long long lower, long long upper) {
        if (root == nullptr) {
            return true;
        }
        if (root->val <= lower || root->val >= upper) {
            return false;
        }
        return check(root->left, lower, root->val) && check(root->right, root->val, upper);
    }
};

// 也可以使用中序遍历, 判断是否为升序
