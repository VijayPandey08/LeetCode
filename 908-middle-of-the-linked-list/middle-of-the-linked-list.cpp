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
    ListNode* middleNode(ListNode* head) {
// ----------------- approach 1 --------------//
        // approach one is to find the length of the linked list and based upon
        // the length is even or odd you need to calculate the centre point, the
        // formula is: (length/2 + 1);
ListNode* temp = head;
        int length = 1;
        while(temp->next!=NULL){
            length++;
            temp = temp->next;
        }

        int mid_position = (length/2) + 1;

        ListNode* mid = head;

        while(mid_position!=1){
            mid = mid->next;
            mid_position--;

        }

        return mid;


// ---------------- approach 2 -------------//
        // will talk about the second approach which is the hare and tortoise
        // algorithm, in which we have two pointer the fast and the slow
        // pointer, when the fast pointer(which walks in 2x speed as of slow
        // pointer) reaches the end of the linked list, at that particular time
        // the slow pointer is exactly at the middle point of the ll

        // ListNode* fast = head;
        // ListNode* slow = head;

        // while(fast->next!=NULL){
        //     fast = fast->next;
        //     if(fast->next!=NULL){
        //         fast = fast->next;
        //         slow = slow->next;
        //     }
        // }

        // return slow;
    }
};