// 第一个错误的版本
// 二分查找

#include "common.h"

bool isBadVersion(int);

class Solution {
public:
    int firstBadVersion(int n) {
        int left = 1, right = n;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (isBadVersion(mid)) {
                right = mid-1;
            } else {
                left = mid+1;
            }
        }
        return left;
    }
};
