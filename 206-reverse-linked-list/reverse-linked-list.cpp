/**
 *Definition for singly-linked list.
 *struct ListNode {
 *   int val;
 *   ListNode * next;
 *   ListNode() : val(0), next(nullptr) {}
 *   ListNode(int x) : val(x), next(nullptr) {}
 *   ListNode(int x, ListNode *next) : val(x), next(next) {}
 *};
 */
class Solution
{
    public:
        ListNode* reverse_using_recurssion(ListNode *prev, ListNode *curr) {
            if(curr==NULL){
                return prev;
            }
            ListNode* nextNode=curr->next;
            curr->next=prev;
            return reverse_using_recurssion(curr,nextNode);

        }
    ListNode* reverseList(ListNode *head)
    {

        ListNode *prev=NULL;
        ListNode* curr=head;
        ListNode* ans = reverse_using_recurssion(prev,curr);

       	// iterative approach
       	// ListNode *prev = NULL;
       	// ListNode *curr = head;
       	// while (curr != NULL)
       	// {
       	//     ListNode *nextNode = curr->next;
       	//     curr->next = prev;
       	//     prev = curr;
       	//     curr = nextNode;
       	// }
       	// return prev;

       	// ab recurssion ki baari
           return ans;

    }
};