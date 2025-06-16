// 分隔链表
// 链表
// 构造链表,虚拟头节点

#include "common.h"

class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        ListNode dummyNodeLarge;
        ListNode dummyNodeSmall;
        ListNode *ps = &dummyNodeSmall;
        ListNode *pl = &dummyNodeLarge;

        while (head != nullptr) {
            if (head->val < x) {
                ps->next = head;
                ps = ps->next;
            } else {
                pl->next = head;
                pl = pl->next;
            }

            ListNode* next = head->next;
            head->next = nullptr;
            head = next;
        }
        ps->next = dummyNodeLarge.next;
        return dummyNodeSmall.next;
    }
};
