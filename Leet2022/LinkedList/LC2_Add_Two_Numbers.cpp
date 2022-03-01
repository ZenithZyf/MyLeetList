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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode origin(0);
        ListNode* dummy = &origin;
        int carry = 0;
        while (l1 || l2) {
            int d1 = l1 ? l1->val : 0;
            int d2 = l2 ? l2->val : 0;
            l1 = l1 ? l1->next : nullptr;
            l2 = l2 ? l2->next : nullptr;
            int sum = d1 + d2 + carry;
            carry = sum / 10;
            dummy->next = new ListNode(sum % 10);
            dummy = dummy->next;
        }
        if (carry) {
            dummy->next = new ListNode(carry);
        }
        return origin.next;
    }
};
