// 二分查找
// 左侧边界,右侧边界

#include "common.h"

class Solution {
public:
    // cpp STL lib
    int countTarget(vector<int>& scores, int target) {
        if(scores.size()==0) return 0;
        auto [first, last] = equal_range(scores.begin(), scores.end(), target);
        return last-first;
    }

};
