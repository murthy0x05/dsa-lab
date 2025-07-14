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
    vector<int> two_power;
public:
    int getDecimalValue(ListNode* head) {
        two_power.assign(30, 1);
        for (int i = 1; i < 30; i++) {
            two_power[i] = 2 * two_power[i - 1];
        }
        
        stack<bool> st;
        for (ListNode* curr = head; curr != nullptr; curr = curr -> next) {
            st.push(curr -> val);
        }
        int result = 0, i = 0;
        while (!st.empty()) {
            if (st.top()) {
                result += two_power[i];
            }
            i++; st.pop();
        }

        return result;
    }
};