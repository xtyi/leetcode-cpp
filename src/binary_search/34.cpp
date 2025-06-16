// 在排序数组中查找元素的第一个和最后一个位置
// 二分查找

#include "common.h"

class Solution {
public:
    int findfirst(vector<int>& nums, int target) {
        int firstpos = -1;
        int left = 0;
        int right = nums.size() - 1;
        while(left <= right) {
            int mid = (left + right) / 2;
            if(nums[mid] == target) {
                firstpos = mid;
                right = mid - 1;
            }
            else if(nums[mid] < target) {
                left = mid + 1;
            }
            else if(nums[mid] > target) {
                right = mid - 1;
            }
        }
        return firstpos;
    }
    int findlast(vector<int>& nums, int target) {
        int lastpos = -1;
        int left = 0;
        int right = nums.size() - 1;
        while(left <= right) {
            int mid = (left + right) / 2;
            if(nums[mid] == target) {
                lastpos = mid;
                left = mid + 1;
            }
            else if(nums[mid] < target) {
                left = mid + 1;
            }
            else if(nums[mid] > target) {
                right = mid - 1;
            }
        }
        return lastpos;
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> res;
        res.push_back(findfirst(nums, target));
        res.push_back(findlast(nums, target));
        return res;
    }
};
