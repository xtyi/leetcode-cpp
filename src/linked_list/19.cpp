// 删除链表的倒数第N个节点
// 链表
// 双指针,快慢指针

#include "common.h"

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode dummy(0, head);
        ListNode* fast = head;
        ListNode* slow = &dummy;
        for (int i = 0; i < n; i++) {
            fast = fast->next;
        }
        while (fast != nullptr) {
            fast = fast->next;
            slow = slow->next;
        }
        slow->next = slow->next->next;
        return dummy.next;
    }
};

int main() {}
