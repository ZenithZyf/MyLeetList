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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode dummy(0);
        ListNode* tail = &dummy;
        
        auto comp = [](ListNode* a, ListNode* b){ return a->val > b->val; };
        priority_queue<ListNode*, vector<ListNode*>, decltype(comp)> pq(comp);
        
        for (auto list : lists) {
            if (list) pq.push(list);
        }
        
        while (!pq.empty()) {
            ListNode* cur = pq.top();
            pq.pop();
            if (cur->next) pq.push(cur->next);
            tail->next = cur;
            tail = tail->next;
        }
        
        return dummy.next;
    }
};
