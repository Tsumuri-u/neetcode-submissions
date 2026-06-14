/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if (!list1)
            return list2;
        if (!list2)
            return list1;

        ListNode* curr1 = list1;
        ListNode* curr2 = list2;
        ListNode* next1 = curr1->next;
        ListNode* next2 = curr2->next;
        ListNode* prev = nullptr;

        while (curr1 && curr2) {
            if (curr1->val <= curr2->val) {
                curr1->next = curr2;
                if (prev)
                    prev->next = curr1;
                prev = curr1;
                curr1 = next1;
                if (curr1)
                    next1 = curr1->next;
            }
            else {
                curr2->next = curr1;
                if (prev)
                    prev->next = curr2;
                prev = curr2;
                curr2 = next2;
                if (curr2)
                    next2 = curr2->next;
            }
        }

        if (list1->val <= list2->val)
            return list1;
        else
            return list2;
    }
};