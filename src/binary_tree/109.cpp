// 有序链表转换二叉搜索树
// 构造树

#include "common.h"

class Solution {
public:
    TreeNode* sortedListToBST(ListNode* head) {
        if (head == nullptr) {
            return nullptr;
        }
        if (head->next == nullptr) {
            return new TreeNode(head->val);
        }
        ListNode* mid = getMid(head);
        TreeNode* root = new TreeNode(mid->val);
        root->left = sortedListToBST(head);
        root->right = sortedListToBST(mid->next);
        return root;
    }

    ListNode* getMid(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;
        ListNode* prev = nullptr;
        while (fast != nullptr && fast->next != nullptr) {
            prev = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        prev->next = nullptr;
        return slow;
    }

    // 也可以先把链表放到数组里
};
