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
    void solve(ListNode* curr , ListNode* prev,ListNode* &head){
        if(curr==NULL) return;
        head = curr;
        solve(curr->next,curr,head);
        curr->next =prev;
    }

    ListNode* reverseList(ListNode* head) {
        if(head==NULL) return head;
        ListNode* temp = new ListNode(NULL);
        solve(head,NULL,temp);
        return temp;
    }
};