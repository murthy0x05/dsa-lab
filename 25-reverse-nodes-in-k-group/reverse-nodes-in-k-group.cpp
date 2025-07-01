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
    void reverse(ListNode* head) {
        if (head == nullptr) {
            return ;
        }
        ListNode* curr = head;
        ListNode* prev = nullptr;
        ListNode* next = nullptr;
        while (curr) {
            next = curr -> next;
            curr -> next = prev;
            prev = curr;
            curr = next;
        }

        return ;
    }
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* prevTail = nullptr;
        ListNode* nextHead = head;
        ListNode* temp = head;
        for (int i = 0; i < k - 1; i++) {
            temp = temp -> next;
        }
        nextHead = temp -> next;
        temp -> next = nullptr;
        reverse(head);
        ListNode* result = temp;
        prevTail = head;

        while (nextHead != nullptr) {
            temp = nextHead;
            for (int i = 0; temp != nullptr && i < k - 1; i++) {
                temp = temp -> next;
            }
            if (temp != nullptr) {
                ListNode* currHead = nextHead;
                nextHead = temp -> next;
                temp -> next = nullptr;
                reverse(currHead);
                prevTail -> next = temp;
                prevTail = currHead;
            } else {
                prevTail -> next = nextHead;
                nextHead = nullptr;
            }
        }


        return result;
    }
};