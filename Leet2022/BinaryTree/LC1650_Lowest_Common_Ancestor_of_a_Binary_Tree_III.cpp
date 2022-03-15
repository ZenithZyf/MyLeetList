/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* parent;
};
*/

class Solution {
public:
    Node* lowestCommonAncestor(Node* p, Node * q) {
        int dp = 0;
        int dq = 0;
        Node* p1 = p;
        Node* q1 = q;
        while (p1) {
            ++dp;
            p1 = p1->parent;
        }
        while (q1) {
            ++dq;
            q1 = q1->parent;
        }
        if (dp < dq) {
            Node* temp = p;
            p = q;
            q = temp;
        }
        for (int i = 0; i < abs(dp - dq); ++i) {
            p = p->parent;
        }
        while (p != q) {
            p = p->parent;
            q = q->parent;
        }
        return p;
    }
};
