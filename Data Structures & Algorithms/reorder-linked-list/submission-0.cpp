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
        // Declare the variable:
        ListNode* slow = head;
        ListNode* fast = head;

        // Check list not null:
        if (!head || !head->next) {
            return;
        }

        // Find the middle list:
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode* second = slow->next;
        slow->next = NULL;

        // Create list for solution:
        // Reverted the slow list
        // Using 2 points to adding elements for their list solution:
        ListNode* prev = NULL;

        while (second) {
            ListNode* temp = second->next;
            second->next = prev; 
            prev = second;
            second = temp;
        }
        second = prev;
        ListNode* first = head;

        while (second) {
            ListNode* tmp1 = first->next;
            ListNode* tmp2 = second->next;

            first->next = second;
            second->next = tmp1;

            first = tmp1;
            second = tmp2;
        }
    }
};
