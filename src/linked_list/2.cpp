// 两数相加
// 链表
// 构造链表,虚拟头节点

#include "common.h"

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode dummyHead;
        ListNode* p = &dummyHead;
        int carry = 0;
        while (l1 != nullptr || l2 != nullptr || carry > 0) {
            int sum = carry;
            if (l1 != nullptr) {
                sum += l1->val;
                l1 = l1->next;
            }
            if (l2 != nullptr) {
                sum += l2->val;
                l2 = l2->next;
            }
            carry = sum / 10;
            sum = sum % 10;
            p->next = new ListNode(sum);
            p = p->next;
        }
        return dummyHead.next;
    }
};
