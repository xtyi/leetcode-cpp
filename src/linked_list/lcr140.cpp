// 链表中倒数第k个节点
// 链表
// 双指针,快慢指针

#include "common.h"

class Solution {
public:
    ListNode* getKthFromEnd(ListNode* head, int k) {
        ListNode *fast = head;
        ListNode dummyHead(0, head);
        ListNode *slow = &dummyHead;
        for (int i = 0; i < k; i++) {
            fast = fast->next;
        }
        while (fast != nullptr) {
            fast = fast->next;
            slow = slow->next;
        }
        return slow->next;
    }
};
