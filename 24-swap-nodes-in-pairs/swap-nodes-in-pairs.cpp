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
    ListNode* swapPairs(ListNode* head) {
        if (head && head -> next) {
            ListNode* next = swapPairs(head -> next -> next);
            ListNode* first = head;
            ListNode* second = head -> next;
            second -> next = first;
            first -> next = next;

            return second;
        } else {
            return head;
        }
    }
};