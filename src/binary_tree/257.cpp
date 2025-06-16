// 二叉树的所有路径
// 深度优先搜索

#include "common.h"

class Solution {
public:
    vector<string> binaryTreePaths(TreeNode* root) {
        // 遍历一遍二叉树就能出结果了
        traverse(root);
        return res;
    }

private:
    // 记录 traverse 函数递归时的路径
    vector<string> path;
    // 记录所有从根节点到叶子节点的路径
    vector<string> res;

    void traverse(TreeNode* root) {
        if (root == nullptr) {
            return;
        }
        // root 是叶子节点
        if (root->left == nullptr && root->right == nullptr) {
            path.push_back(to_string(root->val));
            // 将这条路径装入 res
            res.push_back(joinPath(path));
            path.pop_back();
            return;
        }
        // 前序遍历位置
        path.push_back(to_string(root->val));
        // 递归遍历左右子树
        traverse(root->left);
        traverse(root->right);
        // 后序遍历位置
        path.pop_back();
    }

    string joinPath(const vector<string>& path) {
        stringstream ss;
        for (size_t i = 0; i < path.size(); ++i) {
            ss << path[i];
            if (i < path.size() - 1) ss << "->";
        }
        return ss.str();
    }
};
