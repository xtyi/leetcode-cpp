// 206. 反转链表
// https://leetcode.cn/problems/reverse-linked-list/
// tags: 链表
// tips: 双指针

#include "common.h"


class Solution {
public:
    // ListNode* reverseList(ListNode* head) {
    //     if (head == nullptr || head->next == nullptr) {
    //         return head;
    //     }
    //     ListNode* last = reverseList(head->next);
    //     head->next->next = head;
    //     head->next = nullptr;
    //     return last;
    // }

    ListNode* reverseList(ListNode* head) {
        ListNode* prev = NULL;
        ListNode* curr = head;
        while (curr != NULL) {
            ListNode* nextTemp = curr->next; // 修改 curr next 的指向前, 先保存下一个节点的位置
            curr->next = prev;
            prev = curr;
            curr = nextTemp;
        }
        return prev;
    }
};
