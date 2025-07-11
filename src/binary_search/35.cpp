// 搜索插入位置
// 二分查找

#include "common.h"

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int left = 0, right = nums.size()-1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] > target) {
                right = right - 1;
            } else if (nums[mid] < target) {
                left = left + 1;
            } else {
                return mid;
            }
        }
        return left;
    }
};
