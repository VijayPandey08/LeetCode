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
    // Function to reverse the linked list
    ListNode* reverseLL(ListNode* head) {
        ListNode* prev_node = NULL;
        ListNode* curr_node = head;
        ListNode* next_node = NULL;

        while (curr_node != NULL) {
            next_node = curr_node->next;
            curr_node->next = prev_node;
            prev_node = curr_node;
            curr_node = next_node;
        }
        return prev_node; // Return new head after reversal
    }

    ListNode* removeNthFromEnd(ListNode* head, int n) {
        // if (head == NULL || (head->next == NULL && n == 1)) {
        //     return NULL;
        // }

        head = reverseLL(head);
        ListNode* temp = head;

        // If the node to remove is the head after reversing (which is the tail originally)
        if (n == 1) {
            temp = temp->next;
            head->next = NULL; // Remove the first node
            head = temp; // Update head to new head
        } else {
            ListNode* temp1 = head;
            ListNode* prev = head;

            while (n > 1) {
                prev = temp1;
                temp1 = temp1->next;
                n--;
            }

            if (temp1->next != NULL) {
                prev->next = temp1->next;
                temp1->next = NULL;
            } else {
                prev->next = NULL;
            }
        }

        head = reverseLL(head);
        return head;
    }
};
