// 215. 数组中的第K个最大元素
// https://leetcode.cn/problems/kth-largest-element-in-an-array/
// tags: 堆排序, 快速选择

#include "common.h"

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        return quickSelect(nums, 0, nums.size() - 1, nums.size() - k);
    }

    int quickSelect(vector<int>& nums, int left, int right, int k) {
        int pivot = partition(nums, left, right);

        if (k < pivot) {
            return quickSelect(nums, left, pivot - 1, k);
        } else if (k > pivot) {
            return quickSelect(nums, pivot + 1, right, k);
        } else {
            return nums[pivot];
        }
    }

    int partition(vector<int>& nums, int left, int right) {
        int pivot = nums[left];
        int i = left;
        int j = right;

        while (i < j) {
            while (i < j && nums[j] >= pivot) {
                j--;
            }
            nums[i] = nums[j];

            while (i < j && nums[i] <= pivot) {
                i++;
            }
            nums[j] = nums[i];
        }
        nums[i] = pivot;
        return i;
    }
};
