class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode dummyHead;
        ListNode* pUniq = &dummyHead;
        ListNode* p = head;
        while (p != nullptr) {
            if (pUniq == &dummyHead || p->val != pUniq->val) {
                pUniq->next = p;
                pUniq = pUniq->next;
            }
            p = p->next;
            pUniq->next = nullptr;
        }
        return dummyHead.next;
    }
};
