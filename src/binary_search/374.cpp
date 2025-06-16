// 猜数字大小
// 二分查找

#include "common.h"

int guess(int num);

class Solution {
public:
    int guessNumber(int n) {
        int low = 0, high = n;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (guess(mid) == -1) {
                high = mid - 1;
            } else if (guess(mid) == 1) {
                low = mid + 1;
            } else {
                return mid;
            }
        }
        return -1;
    }
};
