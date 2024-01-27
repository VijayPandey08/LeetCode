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
        ListNode* temp1=l1;
        ListNode* temp2=l2;
        ListNode* dummy= new ListNode(0);
        ListNode* prev=dummy;
        int carry=0;
        while(temp1 && temp2){
             int totalsum = temp1->val+temp2->val+carry;
             int digit = totalsum%10;
             carry=totalsum/10;
             ListNode *mc=new ListNode(digit);
             prev->next=mc;
             prev=prev->next;
             temp1=temp1->next;
             temp2=temp2->next;
        }
        if(!temp1 && !temp2){
            if(carry!=0){
                ListNode * nnode= new ListNode(carry);
                prev->next=nnode;
                return dummy->next;
            }
        }
        if(!temp1){
            while(temp2){
            int totalsum = temp2->val+carry;
             int digit = totalsum%10;
             carry=totalsum/10;
               ListNode *mc=new ListNode(digit);
             prev->next=mc;
             prev=prev->next;
             temp2=temp2->next;
            }
            if(carry!=0){
                ListNode * nnode= new ListNode(carry);
                prev->next=nnode;
                return dummy->next;
            }

        }

                if(!temp2){
            while(temp1){
            int totalsum = temp1->val+carry;
             int digit = totalsum%10;
             carry=totalsum/10;
              ListNode *mc=new ListNode(digit);
             prev->next=mc;
             prev=prev->next;
             temp1=temp1->next;
            }
            if(carry!=0){
                ListNode * nnode= new ListNode(carry);
                prev->next=nnode;
                return dummy->next;
            }

        }
        return dummy->next;
    }
};