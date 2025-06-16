// 回文链表
// 链表
// 数组保存节点地址, 然后判断回文

#include "common.h"

class Solution {
public:
    bool isPalindrome(ListNode* head) {
        vector<ListNode*> v;
        ListNode* p = head;
        while (p != nullptr) {
            v.push_back(p);
            p = p->next;
        }
        for (int i = 0; i < v.size() / 2; i++) {
            if (v[i]->val != v[v.size() - i - 1]->val) {
                return false;
            }
        }
        return true;
    }
};
