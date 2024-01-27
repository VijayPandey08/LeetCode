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
 ListNode* mergeTwoLists(ListNode *list1, ListNode *list2)
        {
            ListNode *dummy = new ListNode(0);
            ListNode *temp1 = dummy;

            while (list1 != NULL && list2 != NULL)
            {
                if (list1->val <= list2->val)
                {
                    temp1->next = list1;
                    list1 = list1->next;
                }
                else
                {
                    temp1->next = list2;
                    list2 = list2->next;
                }
                temp1 = temp1->next;
            }
            if (list1 == NULL) {
                temp1->next=list2;
            }
             if (list2 == NULL) {
                temp1->next=list1;
            }
            return dummy->next;
        }
    ListNode* sortList(ListNode* head) {
        if(!head ||!head->next){
            return head;
        }
        ListNode * fast=head;
        ListNode * slow= head;
        ListNode * prev=NULL;
        while(fast && fast->next){
            prev=slow;
            slow=slow->next;
            fast=fast->next->next;
        }
        prev->next=NULL;
        ListNode * l1=sortList(head);
        ListNode * l2=sortList(slow);
        return mergeTwoLists(l1,l2);
    }
};