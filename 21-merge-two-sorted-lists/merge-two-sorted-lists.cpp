class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* temp = NULL;
        ListNode* head = NULL;

        // Check if list1 or list2 is null before accessing their values
        if (!list1) {
            return list2;
        } else if (!list2) {
            return list1;
        } else if (list1->val <= list2->val) {
            temp = list1;
            head = list1;
            list1 = list1->next;
        } else {
            temp = list2;
            head = list2;
            list2 = list2->next;
        }

        while (list1 != NULL || list2 != NULL) {
            if (list1 == NULL) {
                temp->next = list2;
                break;
            } else if (list2 == NULL) {
                temp->next = list1;
                break;
            } else if (list1->val <= list2->val) {
                temp->next = list1;
                list1 = list1->next;
            } else {
                temp->next = list2;
                list2 = list2->next;
            }
            temp = temp->next;
        }

        return head;
    }
};
