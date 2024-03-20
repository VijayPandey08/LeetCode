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
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        // a->next ko list2 ki starting se jodhna h
        // list2 ke end ko b se jodhna h..

        // a->next tak pahucho
        ListNode* atr = list1;
        for(int i=0; i<a-1; i++){
              atr=atr->next;
        }

        // b->next ko vha tak pahuchao jha tak list2 ka aakhri node jana chahiye
        ListNode* btr = atr->next;
        for(int i=0; i<b-a+1; i++){
            btr=btr->next;
        }

        // a ke next ko list2 ki starting mein jodo
        atr->next=list2;
        
        // ab list2 ko aakhri tak leke jaao aur frr use b par jodh dena
        while(list2->next){
           list2=list2->next;
        }
        // list2 ke aakhri ko b se jodh dia
        list2->next=btr;

        // list1 ko return karwa dia
        return list1;
    }
};