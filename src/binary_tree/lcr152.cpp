// 验证二叉搜索树的后序遍历序列
// 递归

#include "common.h"

class Solution {
public:
    bool verifyTreeOrder(vector<int>& postorder) {
        return verify(postorder, 0, postorder.size()-1);
    }

    bool verify(vector<int>& postorder, int low, int high) {
        if (low >= high) {
            return true;
        }
        int root = postorder[high];
        int idx = low;
        while (postorder[idx] < root) {
            idx++;
        }
        for (int i = idx; i < high; i++) {
            if (postorder[i] <= root) {
                return false;
            }
        }
        return verify(postorder, low, idx-1) && verify(postorder, idx, high-1);
    }
};
