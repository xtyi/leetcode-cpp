// 合并K个升序链表
// 链表
// 优先队列

#include "common.h"

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (lists.empty()) {
            return nullptr;
        }
        ListNode dummy;
        ListNode* p = &dummy;

        auto cmp = [](ListNode* a, ListNode* b) {
            return a->val > b->val;
        };
        priority_queue<ListNode*, vector<ListNode*>, decltype(cmp)> pq(cmp);
        for (ListNode* head: lists) {
            if (head != nullptr) {
                pq.push(head);
            }
        }

        while (!pq.empty()) {
            ListNode* node = pq.top();
            pq.pop();

            if (node->next != nullptr) {
                pq.push(node->next);
            }

            p->next = node;
            p = p->next;
        }
        return dummy.next;
    }
};
