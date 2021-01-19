/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* cloneGraph(Node* node) {
        if (!node) return nullptr;
        
        unordered_set<Node*> done;
        unordered_map<Node*, Node*> m;
        queue<Node*> q;
        q.push(node);
        while (!q.empty()) {
            Node* n = q.front(); q.pop();
            if (done.count(n)) continue;
            done.insert(n);
            if (!m.count(n))
                m[n] = new Node(n->val);
            Node* t = m[n];
            for (Node* s : n->neighbors) {
                if (!m.count(s))
                    m[s] = new Node(s->val);
                q.push(s);
                t->neighbors.push_back(m[s]);
            }
        }
        return m[node];
    }
};
