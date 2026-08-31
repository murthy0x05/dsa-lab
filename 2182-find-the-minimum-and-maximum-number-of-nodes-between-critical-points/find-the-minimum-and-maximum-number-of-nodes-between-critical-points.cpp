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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        ListNode* prev = head;
        ListNode* curr = head -> next;

        int i = 1;
        while (curr and
               curr -> next and
               !((curr -> val > prev -> val and curr -> val > curr -> next -> val) or 
               (curr -> val < prev -> val and curr -> val < curr -> next -> val))
        ) {
            prev = curr;
            curr = curr -> next;
            i++;
        }

        if (!curr -> next) {
            return {-1, -1};
        }
        
        int smallest = INT_MAX, largest = INT_MIN;
        int start = i;
        int pi = i;
        while (curr and curr -> next) {
            prev = curr;
            curr = curr -> next;
            i++;
            while (curr and
                curr -> next and
                !((curr -> val > prev -> val and curr -> val > curr -> next -> val) or 
                (curr -> val < prev -> val and curr -> val < curr -> next -> val))
            ) {
                prev = curr;
                curr = curr -> next;
                i++;
            }

            if (curr and curr -> next) {
                smallest = min(smallest, i - pi);
                largest = i - start;
                pi = i;
            }
        }
        
        if (smallest == INT_MAX)
            return {-1, -1};
        return {smallest, largest};
    }
};