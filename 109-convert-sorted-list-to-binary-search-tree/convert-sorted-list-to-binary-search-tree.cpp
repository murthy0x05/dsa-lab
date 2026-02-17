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
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* sortedListToBST(ListNode* head) {
        vector<int> nums;
        for (ListNode* curr = head; curr; curr = curr -> next) {
            nums.push_back(curr -> val);
        }

        function<TreeNode*(int, int)> buildBST = [&] (int low, int high) {
            if (low > high) 
                return (TreeNode*) nullptr;
            
            int mid = low + ((high - low) >> 1);
            TreeNode* node = new TreeNode(nums[mid]);
            node -> left = buildBST(low, mid - 1);
            node -> right = buildBST(mid + 1, high);

            return node;
        };

        return buildBST(0, nums.size() - 1);
    }
};