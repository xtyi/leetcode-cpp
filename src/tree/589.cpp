// 589. N 叉树的前序遍历
// https://leetcode.cn/problems/n-ary-tree-preorder-traversal/
// tags: 树
// tips: 递归

#include "common.h"

class Solution {
    vector<int> ans;
public:
    vector<int> preorder(Node* root) {
        dfs(root);
        return ans;
    }

    void dfs(Node* root) {
        if (root == nullptr) return;
        ans.push_back(root->val);
        for (Node* child : root->children) {
            dfs(child);
        }
    }
};
