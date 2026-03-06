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
    ListNode* mergeNodes(ListNode* head) {
        ListNode* dummy = new ListNode(0);
        ListNode* node = dummy;

        int currSum = 0;
        for (ListNode* curr = head -> next; curr; curr = curr -> next) {
            if (curr -> val == 0) {
                node -> next = new ListNode(currSum);
                node = node -> next;
                currSum = 0;
            } else {
                currSum += curr -> val;
            }
        }

        ListNode* result = dummy -> next;
        delete(dummy);
        return result;
    }
};