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
    ListNode* partition(ListNode* head, int x) {
        ListNode* head1 = new ListNode(0);
        ListNode* head2 = new ListNode(0);
        ListNode* dummy1 = head1, *dummy2 = head2;

        for (ListNode* curr = head; curr; curr = curr -> next) {
            if (curr -> val < x) {
                head1 -> next = curr;
                head1 = head1 -> next;
            } else {
                head2 -> next = curr;
                head2 = head2 -> next;
            }
        }

        head1 -> next = nullptr;
        head2 -> next = nullptr;

        ListNode* p1 = dummy1 -> next;
        ListNode* p2 = dummy2 -> next;
        delete dummy1, dummy2;
        
        if (!p1) {
            return p2;
        } else if (!p2) {
            return p1;
        } else {
            head1 -> next = p2;
            return p1;
        }
    }
};