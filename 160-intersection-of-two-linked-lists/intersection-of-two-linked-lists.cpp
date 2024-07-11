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
    ListNode* getIntersectionNode(ListNode* headA, ListNode* headB) {
        unordered_map<ListNode*, bool> m;
        ListNode* temp1 = headA;
        ListNode* temp2 = headB;

        while (temp1 != NULL || temp2 != NULL) {
            if (temp1 != NULL) {
                if (m.find(temp1) != m.end()) {
                    return temp1;
                } else {
                    m[temp1] = true;
                }
            temp1 = temp1->next;
            }

            if (temp2 != NULL) {
                if (m.find(temp2) != m.end()) {
                    return temp2;
                } else {
                    m[temp2] = true;
                }
            temp2 = temp2->next;
            }
        }

        return NULL;
    }
};