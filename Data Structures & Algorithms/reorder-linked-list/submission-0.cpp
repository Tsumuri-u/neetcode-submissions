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
    void reorderList(ListNode* head) {
        if (!head) return;

        ListNode* slow = head;
        ListNode* fast = head;

        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }

        // reverse second half
        ListNode* second = slow->next;
        slow->next = nullptr;
        ListNode* prev = nullptr;
        ListNode* temp;

        while (second) {
            temp = second->next;
            second->next = prev;
            prev = second;
            second = temp;
        }
        
        // merge halves
        ListNode* first = head;
        second = prev;
        ListNode* tempFirst;
        ListNode* tempSecond;

        while (second) {
            tempFirst = first->next;
            tempSecond = second->next;
            first->next = second;
            second->next = tempFirst;
            first = tempFirst;
            second = tempSecond;
        }
    }
};
