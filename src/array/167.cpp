// 167. 两数之和 II - 输入有序数组
// https://leetcode.cn/problems/two-sum-ii-input-array-is-sorted/
// tags: 数组
// tips: 双指针

#include "common.h"

// 数组有序, 可以使用双指针
class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int lo = 0, hi = numbers.size() - 1;
        while (lo < hi) {
            int sum = numbers[lo] + numbers[hi];
            if (sum < target) lo++;
            else if (sum > target) hi--;
            else return {lo+1, hi+1};
        }
        return {};
    }
};
