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
int len(ListNode* head){
    int count=0;
    while(head!=NULL){
        count++;
        head=head->next;
    }
    return count;
}
    ListNode* reverseLL(ListNode* head, int k){
    if(head==NULL || head->next==NULL){
        return head;
    }
    if(len(head)<k){
        return head;
    }
     ListNode* prev=NULL;
     ListNode* curr=head;
    int count=0;
     while(count<k){
         count++;
         ListNode* temp=curr->next;
         curr->next=prev;
         prev=curr;
         curr=temp;
     }
    head->next=reverseLL(curr,k);
    return prev;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
       
    return reverseLL(head,k);
    }
};