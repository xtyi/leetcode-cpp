// 相交链表
// 链表
// 双指针

#include "common.h"

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if (headA == nullptr || headB == nullptr) {
            return nullptr;
        }
        ListNode* pa = headA;
        ListNode* pb = headB;
        while (pa != pb) {
            if (pa == nullptr) {
                pa = headB;
            } else {
                pa = pa->next;
            }
            if (pb == nullptr) {
                pb = headA;
            } else {
                pb = pb->next;
            }
        }
        return pa;
    }
};

int main() {}

