/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (!head) return head;

        map<Node*, Node*> m;
        Node* curr = head;
        Node* prev = NULL;
        Node* newHead = NULL;

        // First pass: create new nodes and store them in the map
        while (curr) {
            Node* temp = new Node(curr->val);
            m[curr] = temp;

            if (!newHead) {
                newHead = temp;
                prev = newHead;
            } else {
                prev->next = temp;
                prev = temp;
            }
            curr = curr->next;
        }

        // Second pass: set the random pointers
        curr = head;
        Node* newCurr = newHead;
        while (curr) {
            if (curr->random == NULL) {
                newCurr->random = NULL;
            } else {
                newCurr->random = m[curr->random];
            }

            newCurr = newCurr->next;
            curr = curr->next;
        }

        return newHead;
    }
};
