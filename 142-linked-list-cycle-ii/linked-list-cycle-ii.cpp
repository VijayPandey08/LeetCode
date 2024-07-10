/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode* temp = head;
        ListNode* fast = temp;
        ListNode* slow = temp;


        while(fast!=NULL){
            fast=fast->next;
            if(fast!=NULL){
                fast=fast->next;
                slow=slow->next;
                if(slow==fast){
                    slow = temp;
                    while(fast!=slow){
                        fast=fast->next;
                        slow=slow->next;
                    }
                    return slow;
                }
            }
        }

        return NULL;
    }
};