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
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* start = head;
        ListNode* end = head;
        for (int i = 0; i < k; ++i) {
            if (!end) {
                return start;
            }
            end = end->next;
        }
        ListNode* last = reverseK(start, end);
        start->next = reverseKGroup(end, k);
        return last;
    }
private:
    ListNode* reverseK(ListNode* head, ListNode* end) {
        ListNode* prev = nullptr;
        ListNode* cur = head;
        ListNode* nxt = head;
        while (cur != end) {
            nxt = cur->next;
            cur->next = prev;
            prev = cur;
            cur = nxt;
        }
        return prev;
    }
};
