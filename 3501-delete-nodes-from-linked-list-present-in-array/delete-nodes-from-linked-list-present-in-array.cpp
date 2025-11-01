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
    int n;
    bool find(vector<int>& nums, const int& target) {
        int low = 0, high = n - 1;
        while (low <= high) {
            int mid = low + ((high - low) >> 1);
            if (nums[mid] == target) {
                return true;
            } else if (nums[mid] < target) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }

        return false;
    }
public:
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        this -> n = nums.size();
        sort(nums.begin(), nums.end());

        ListNode* dummy = new ListNode();
        ListNode* node = dummy;
        for (ListNode* curr = head; curr; curr = curr -> next) {
            if (!find(nums, curr -> val)) {
                node -> next = curr;
                node = node -> next;
            }
        }
        node -> next = nullptr;

        ListNode* result = dummy -> next;
        delete(dummy);

        return result;       
    }
};