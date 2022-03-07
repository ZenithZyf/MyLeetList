/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution {
public:
    Node* flatten(Node* head) {
        Node* cur = head;
        while (cur) {
            if (cur->child) {
                Node* nxt = cur->next;
                Node* lst = cur->child;
                while (lst->next) {
                    lst = lst->next;
                }
                cur->next = cur->child;
                cur->next->prev = cur;
                cur->child = nullptr;
                lst->next = nxt;
                if (nxt) {
                    nxt->prev = lst;
                }
            }
            cur = cur->next;
        }
        return head;
    }
};
