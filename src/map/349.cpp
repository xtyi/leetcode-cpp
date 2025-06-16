// 两个数组的交集
// 哈希表

#include "common.h"

class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> set1(nums1.begin(), nums1.end());
        unordered_set<int> set2;
        for (int v : nums2) {
            if (set1.count(v))
                set2.insert(v);
        }
        return vector<int>(set2.begin(), set2.end());
    }
};

