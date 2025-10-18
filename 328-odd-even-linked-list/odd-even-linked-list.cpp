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
    ListNode* oddEvenList(ListNode* head) {
        if (!head || !head -> next) return head;
        
        ListNode* dummy_o = new ListNode(),
                * dummy_e = new ListNode();
        ListNode* d1 = dummy_o,
                * d2 = dummy_e;
        ListNode* curr = nullptr;
        for (curr = head; curr && curr -> next; curr = curr -> next -> next) {
            d1 -> next = curr;
            d1 = d1 -> next;
            if (d1 -> next) {
                d2 -> next = d1 -> next;
                d2 = d2 -> next;
            }
        }
        if (curr) {
            d1 -> next = curr;
            d1 = d1 -> next;
        }
        d2 -> next = nullptr;
        d1 -> next = dummy_e -> next;
        
        ListNode* odd = dummy_o -> next;
        delete(dummy_o);
        delete(dummy_e);

        return odd;

    }
};