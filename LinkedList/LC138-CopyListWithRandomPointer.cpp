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
        
        unordered_map<Node*, Node*> mp;
        Node* cur = mp[head] = new Node(head->val);
        Node* res = cur;
        while (head) {
            if (head->random) {
                auto it = mp.find(head->random);
                if (it == mp.end()) {
                    it = mp.emplace(head->random, new Node(head->random->val)).first;
                }
                cur->random = it->second;
            }
            if (head->next) {
                auto it = mp.find(head->next);
                if (it == mp.end()) {
                    it = mp.emplace(head->next, new Node(head->next->val)).first;
                }
                cur->next = it->second;
            }
            cur = cur->next;
            head = head->next;
        }
        return res;
    }
};
