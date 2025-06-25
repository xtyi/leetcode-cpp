// 3. 无重复字符的最长子串
// https://leetcode.cn/problems/longest-substring-without-repeating-characters/
// tags: 滑动窗口

#include "common.h"

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> windows;
        int left, right = 0;
        int ans = 0;
        while (right < s.size()) {
            char c = s[right];
            right++;
            windows[c]++;

            // 不符合时缩小窗口, 直到符合
            while (windows[c] > 1) {
                char d = s[left];
                left++;
                windows[d]--;
            }

            // 缩小窗口后, 更新结果
            ans = max(ans, right-left);
        }
        return ans;
    }
};
