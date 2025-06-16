// 寻找两个正序数组的中位数
// 二分查找

#include "common.h"

class Solution {
public:
    // O(m+n)
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int> ans;
        int i1 = 0, i2 = 0;
        while (i1 < nums1.size() && i2 < nums2.size()) {
            if (nums1[i1] < nums2[i2]) {
                ans.push_back(nums1[i1]);
                i1++;
            } else {
                ans.push_back(nums2[i2]);
                i2++;
            }
        }
        while (i1 < nums1.size()) {
            ans.push_back(nums1[i1++]);
        }
        while (i2 < nums2.size()) {
            ans.push_back(nums2[i2++]);
        }
        int n = ans.size();
        if (n % 2 == 0) {
            return (ans[n/2-1] + ans[n/2]) / 2.0;
        } else {
            return ans[n/2];
        }
    }

    // 二分 O(log(m+n))
    // TODO
};
