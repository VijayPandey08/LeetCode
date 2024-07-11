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
    ListNode* reverseLL(ListNode* curr, ListNode* prev) {
        if (curr == NULL) {
            return prev;
        }
        ListNode* next = curr->next;
        curr->next = prev;

        return reverseLL(next, curr);
    }
    bool isPalindrome(ListNode* head) {
        ListNode* head1 = head;
        ListNode* fast = head;
        ListNode* slow = head;

        while (fast->next != NULL) {
            fast = fast->next;
            if (fast->next != NULL) {
                fast = fast->next;
                slow = slow->next;
            }
        }

        ListNode* temp = slow->next;
        slow->next = NULL;

        ListNode* head2 = reverseLL(temp, NULL);

        while (head2 != NULL) {
            if (head1->val != head2->val)
                return false;
            head1 = head1->next;
            head2 = head2->next;
        }

        return true;
    }
};