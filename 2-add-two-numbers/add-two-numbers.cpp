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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* dummy = new ListNode(0);
        ListNode* curr = dummy;

        ListNode* temp1 = l1;
        ListNode* temp2 = l2;

        int carry = 0;

        while (temp1 != NULL || temp2 != NULL) {
            int sum = 0;
            if (temp1){

                sum += temp1->val;
                temp1 = temp1->next;
            }
            if (temp2){

                sum += temp2->val;
                temp2 = temp2->next;
            }
            sum += carry;
            int digit = sum % 10;
            carry = sum / 10;
            ListNode* new_node = new ListNode(digit);
            curr->next = new_node;
            curr = new_node;
            // if (temp1)
            // if (temp2)
        }

        if (carry) {
            ListNode* new_node1 = new ListNode(carry);
            curr->next = new_node1;
        }
        return dummy->next;
    }
};