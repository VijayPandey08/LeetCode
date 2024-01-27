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
            // if(!list1 && !list2) return NULL;
            // if(list1==NULL) return list2;
            // if(list2==NULL) return list1;
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
    ListNode* solve(vector<ListNode*>& lists, int start,int end){
        // base case
        if(start>end){
            return NULL;
        }
        if(start==end){
            return lists[start];
        }
        int mid=(start+end)/2;
        ListNode * l1=solve(lists, start,mid);
        ListNode *l2=solve(lists, mid+1,end);
        return mergeTwoLists(l1,l2);
    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int start=0;
        int end=lists.size()-1;
        return solve(lists,start,end);
    }
};