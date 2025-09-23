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
    ListNode* reverseEvenLengthGroups(ListNode* head) {
        int n = 0;
        for (ListNode* curr = head; curr != nullptr; curr = curr -> next) n++;

        int group = 1, i = 0;
        ListNode* dummy = new ListNode();
        dummy -> next = head;
        ListNode* node = dummy;
        while (i < n) {
            int len = min(group, n - i);
            if (len & 1) {
                node = node -> next;
                int skips = len - 1;
                while (skips--) {
                    node = node -> next;
                }
            } else {
                int k = len;
                ListNode* prevTail = node;
                cout << prevTail -> val << endl;
                ListNode* currTail = node -> next;
                node = node -> next;
                ListNode* prev = nullptr,
                        * curr = node;
                while (curr && k--) {
                    ListNode* next = curr -> next;
                    curr -> next = prev;
                    prev = curr;
                    curr = next;
                }

                prevTail -> next = prev;
                currTail -> next = curr;
                node = currTail;
            }

            i += len;
            group++;
        }

        return head;
    }
};