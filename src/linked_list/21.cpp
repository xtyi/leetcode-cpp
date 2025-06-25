// 21. 合并两个有序链表
// https://leetcode.cn/problems/merge-two-sorted-lists/
// tags: 链表
// tips: 构造链表,虚拟头节点

#include "common.h"

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode dummy;
        ListNode* p = &dummy;
        ListNode* p1 = list1;
        ListNode* p2 = list2;
        while (p1 != nullptr && p2 != nullptr) {
            if (p1->val < p2->val) {
                p->next = p1;
                p1 = p1->next;
            } else {
                p->next = p2;
                p2 = p2->next;
            }
            p = p->next;
        }
        if (p1 != nullptr) {
            p->next = p1;
        }
        if (p2 != nullptr) {
            p->next = p2;
        }
        return dummy.next;
    }
};

int main() {}
