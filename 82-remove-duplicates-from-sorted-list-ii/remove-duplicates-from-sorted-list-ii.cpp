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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* dummy = new ListNode();
        ListNode* curr = dummy, *prev = new ListNode(INT_MIN);

        while (head) {
            while (head && head -> next && head -> val == head -> next -> val) {
                prev = head;
                head = head -> next;
            }
            if (prev -> val != head -> val) {
                curr -> next = head;
                curr = curr -> next;
            }
            head = head -> next;
        }
        
        curr -> next = nullptr;
        ListNode* result = dummy -> next;
        delete(dummy);

        return result;
    }
};