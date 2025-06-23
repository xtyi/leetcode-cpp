#include "common.h"


class Solution {
public:
    string minWindow(string s, string t) {

        unordered_map<char, int> window;
        unordered_map<char, int> need;
        int valid = 0;
        for (auto ch: t) {
            need[ch] += 1;
        }
        int start = 0, len = INT_MAX;

        int left = 0, right = 0;

        while (right < s.size()) {
            auto ch = s[right];
            right++;
            if (need.count(ch)) {
                window[ch] += 1;
                if (window[ch] == need[ch]) {
                    valid += 1;
                }
            }

            // 符合时缩小窗口, 直到即将不符合
            while (valid == need.size()) {
                // 这里更新结果
                if (right - left < len) {
                    start = left;
                    len = right - left;
                }

                auto ch = s[left];
                left++;

                if (need.count(ch)) {
                    if (window[ch] == need[ch]) {
                        valid -= 1;
                    }
                    window[ch] -= 1;
                }
            }
        }

        return len == INT_MAX ? "" : s.substr(start, len);
    }
};
