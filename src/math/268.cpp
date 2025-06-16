// 丢失的数字
// 数学
// 排序,位运算

#include "common.h"

class Solution {
public:
    // 排序
    // int missingNumber(vector<int>& nums) {
    //     sort(nums.begin(),nums.end());
    //     int n = nums.size();
    //     for (int i = 0; i < n; i++) {
    //         if (nums[i] != i) {
    //             return i;
    //         }
    //     }
    //     return n;
    // }

    // 位运算
    int missingNumber(vector<int>& nums) {
        int res = 0;
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            res ^= nums[i];
        }
        for (int i = 0; i <= n; i++) {
            res ^= i;
        }
        return res;
    }

    // 高斯公式
    // int missingNumber(vector<int>& nums) {
    //     int n = nums.size();
    //     int total = n * (n + 1) / 2;
    //     int arrSum = 0;
    //     for (int i = 0; i < n; i++) {
    //         arrSum += nums[i];
    //     }
    //     return total - arrSum;
    // }


};

