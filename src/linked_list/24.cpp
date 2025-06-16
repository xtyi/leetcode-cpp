// 两两交换链表中的节点
// 链表
// 反转链表

#include "common.h"

class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        ListNode dummyHead(0, head);
        ListNode* pre = &dummyHead;
        while (pre->next != nullptr && pre->next->next != nullptr) {
            ListNode* node1 = pre->next;
            ListNode* node2 = pre->next->next;
            pre->next = node2;
            node1->next = node2->next;
            node2->next = node1;
            pre = node1;
        }
        return dummyHead.next;
    }
};
