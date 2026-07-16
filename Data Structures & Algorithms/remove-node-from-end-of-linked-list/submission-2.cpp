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
    ListNode* removeNthFromEnd(ListNode* head, int n) {

        // count items in list
        int count = 0;
        ListNode* curr = head;
        while (curr) {
            count++;
            curr = curr->next;
        }

        // handle edge cases
        if (count == 1)
            return nullptr;
        if (n == count)
            return head->next;

        // remove the node
        count = count - n + 1;
        curr = head;
        ListNode* temp = nullptr;
        ListNode* prev = nullptr;

        while (count) {
            count--;
            if (!count)
                prev->next = temp;
            prev = curr;
            curr = curr->next;
            temp = curr->next;
        }

        return head;
    }
};
