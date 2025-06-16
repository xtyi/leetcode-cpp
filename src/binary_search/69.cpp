// x 的平方根
// 二分查找

#include "common.h"

class Solution {
public:
    int mySqrt(int x) {
        int left = 1;
        int right = x/2 + 1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (mid > x/mid) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        return left-1;
    }
};
