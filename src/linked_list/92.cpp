// 反转链表II
// 链表
// 反转

#include "common.h"

class Solution {
public:
    ListNode* reverseN(ListNode* head, int n) {
        if (head == nullptr || head->next == nullptr) {
            return head;
        }
        ListNode *pre = nullptr;
        ListNode* cur = head;
        ListNode* nxt = head->next;

        while (n > 0) {
            // 修改只有这一行
            cur->next = pre;
            pre = cur;
            cur = nxt;
            if (nxt != nullptr) {
                nxt = nxt->next;
            }
            n--;
        }
        head->next = cur;
        return pre;
    }

    ListNode* reverseBetween(ListNode* head, int m, int n) {
        if (m == 1) {
            return reverseN(head, n);
        }
        ListNode* pre = head;
        for (int i = 1; i < m-1; i++) {
            pre = pre->next;
        }
        pre->next = reverseN(pre->next, n-m+1);
        return head;
    }

};
