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
    void deleteNode(ListNode* node) {
        // this is purely a genius question, and one-liner question
        // given node ko delete krna h, aur na hi head dia h na kuch
        // toh iterate kese kre...?
        // answer: node (tail nhi h yeh given h) toh iske aage koi node hogi, uski value iss node pe copy kr lo, aur agle node ko skip krte hue aage bdh jaaao, jisse yeh node agle node ki tarah kaam krega aur agla node picture se gayab ho jaaega
        // esa krne se agle node ki exact copy bach gyi (q ki use humne pehle hi copy kr lia tha) pr jo actual node tha vo gayab ho gya jesa ki hum chahte the


        node->val = node->next->val;
        node->next = node->next->next;

    }
};