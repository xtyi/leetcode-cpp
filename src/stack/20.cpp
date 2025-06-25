// 20. 有效的括号
// https://leetcode.cn/problems/valid-parentheses/
// tags: 栈

#include "common.h"

class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        for (char c : s) {
            if (c == '(' || c == '[' || c == '{') {
                st.push(c);
            } else {
                if (st.empty()) return false;
                char top = st.top();
                if (c == ')' && top != '(') return false;
                if (c == ']' && top != '[') return false;
                if (c == '}' && top != '{') return false;
                st.pop();
            }
        }
        return st.empty();
    }
};
