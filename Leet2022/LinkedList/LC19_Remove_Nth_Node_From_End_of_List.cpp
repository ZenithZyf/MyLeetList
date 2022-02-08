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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode dummy(0);
        dummy.next = head;
        ListNode* x = findFromEnd(&dummy, n + 1);
        x->next = x->next->next;
        return dummy.next;     
    }
private:
    ListNode* findFromEnd(ListNode* head, int n) {
        ListNode* p1 = head;
        ListNode* p2 = head;
        for (int i = 0; i < n; ++i) {
            p1 = p1->next;
        }
        while (p1) {
            p1 = p1->next;
            p2 = p2->next;
        }
        return p2;
    }
};
