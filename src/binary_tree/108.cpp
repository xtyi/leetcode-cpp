// 将有序数组转换为二叉搜索树
// 构造树

#include "common.h"

class Solution {
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return vecToTree(nums, 0, nums.size()-1);
    }

    TreeNode* vecToTree(vector<int>& nums, int low, int high) {
        if (low > high) {
            return nullptr;
        }
        if (low == high) {
            return new TreeNode(nums[low]);
        }
        int mid = (low + high) / 2;
        auto root = new TreeNode(nums[mid]);
        root->left = vecToTree(nums, low, mid-1);
        root->right = vecToTree(nums, mid+1, high);
        return root;
    }
};
