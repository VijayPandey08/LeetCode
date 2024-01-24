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
    bool hasCycle(ListNode *head) {
   
   ListNode* slow =head;
   ListNode* fast=head;
   while(fast!=NULL){
       fast=fast->next;
       if(fast!=NULL){
           fast=fast->next;
           slow=slow->next;
       }
       if(fast==slow){
           return true;
       }
   }
   return false;
   
   
    // map vala logic 
    //   map<ListNode* , bool> table;
    //   ListNode* temp=head;
    //   while(temp!=NULL){
    //       if(table[temp]==false){
    //           table[temp]=true;
    //           temp=temp->next;
    //       }
    //       else{
    //           return true;
    //       }
    //   }  
    //   return false;
    }
};