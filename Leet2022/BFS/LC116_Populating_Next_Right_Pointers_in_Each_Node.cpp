/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        if (!root) return root;
        queue<Node*> q_nodes;
        q_nodes.push(root);
        
        while (!q_nodes.empty()) {
            int sz = q_nodes.size();
            for (int i = 0;  i < sz; ++i) {
                Node* cur_node = q_nodes.front(); q_nodes.pop();
                if (i < sz - 1) {
                    cur_node->next = q_nodes.front();
                }
                if (cur_node->left) {
                    q_nodes.push(cur_node->left);
                    q_nodes.push(cur_node->right);
                }
            }
        }
        
        return root;
    }
};
