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
        Node* pp = p;
        Node* qq = q;
        
        while (pp != NULL) {
            dp++;
            pp = pp->parent;
        }
        while (qq != NULL) {
            dq++;
            qq = qq->parent;
        }
        if (dq > dp) {
            Node* tmp = q;
            q = p;
            p = tmp;
        }
        for (int i = 0; i < abs(dp - dq); i++) {
            p = p->parent;
        }
        
        while (p != q) {
            p = p->parent;
            q = q->parent;
        }
        
        return q;
    }
};
