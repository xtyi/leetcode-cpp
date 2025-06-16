// 环形链表II
// 链表
// 哈希表存储节点地址

#include "common.h"

class Solution {
public:
    ListNode* detectCycle(ListNode *head) {
        unordered_set<ListNode*> s;
        ListNode* p = head;
        while (p != nullptr) {
            if (s.find(p) != s.end()) {
                return p;
            }
            s.insert(p);
            p = p->next;
        }
        return nullptr;
    }
};

int main() {}
