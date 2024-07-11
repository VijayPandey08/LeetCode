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
    int getLen(ListNode* head) {
        int len = 0;
        while (head != NULL) {
            len++;
            head = head->next;
        }
        return len;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {

        // if (head == NULL || head->next == NULL) {
        //     return head;
        // }
        
        ListNode* temp = head;
        ListNode* curr = temp;
        ListNode* prev = NULL;

        int len = getLen(temp);

        if (len < k) {
            return head;
        }

        int pos = 0;
        while (pos < k) {
            ListNode* next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
            pos++;
        }

        ListNode* recAns = NULL;
        if (curr != NULL) {
            recAns = reverseKGroup(curr, k);
            head->next = recAns;
        }

        return prev;
    }
};