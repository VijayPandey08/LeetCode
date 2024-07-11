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
    ListNode* rotateRight(ListNode* head, int k) {
        if (!head || k == 0) return head; // Early exit for empty list or no rotation
        
        int len = 0;
        ListNode* temp = head;
        ListNode* tail = nullptr;

        // Calculate the length of the list and get the tail node
        while (temp != nullptr) {
            len++;
            tail = temp;
            temp = temp->next;
        }

        k = k % len; // Effective rotations needed
        if (k == 0) return head; // No rotation needed if k is a multiple of len

        ListNode* temp1 = head;
        for (int i = 0; i < len - k - 1; i++) {
            temp1 = temp1->next;
        }

        ListNode* newHead = temp1->next; // The new head after rotation
        temp1->next = nullptr; // Break the link
        tail->next = head; // Link the end of the list to the original head

        return newHead;
    }
};
