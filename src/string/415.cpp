// 415. 字符串相加
// https://leetcode.cn/problems/add-strings/
// tags: 字符串

#include "common.h"

class Solution {
public:
    string addStrings(string num1, string num2) {
        int i = num1.size() - 1;
        int j = num2.size() - 1;
        int carry = 0;
        string result;
        while (i >= 0 || j >= 0 || carry > 0) {
            int x = i >= 0 ? num1[i] - '0' : 0;
            int y = j >= 0 ? num2[j] - '0' : 0;
            int sum = x + y + carry;
            result.push_back(sum % 10 + '0');
            carry = sum / 10;
            i--;
            j--;
        }
        reverse(result.begin(), result.end());
        return result;
    }
};
