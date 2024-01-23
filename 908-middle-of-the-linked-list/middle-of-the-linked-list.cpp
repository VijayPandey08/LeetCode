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
    int getlen(ListNode* head){
        int count=0;
        ListNode* temp=head;
        while(temp!=NULL){
            count++;
            temp=temp->next;
        }
        return count;
    } 
    ListNode* middleNode(ListNode* head) {
        int n=getlen(head);
        int position = n/2 +1;
            ListNode* temp1=head;
        while(position!=1){
            position--;
            temp1=temp1->next;
        }
        return temp1;
    }
};