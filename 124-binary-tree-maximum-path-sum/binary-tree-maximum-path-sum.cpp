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
    int maxSum = INT_MIN;
public:
    int solve(TreeNode* root) {
        if (!root) {
            return 0;
        }

        int leftSum = solve(root -> left);
        int rightSum = solve(root -> right);
        //         if (root -> left) {
        //     leftSum = solve(root -> left);            
        // } // 2
        // if (root -> right) {
        //     rightSum = solve(root -> right);
        // } // 3
        
        int down = root -> val + max(leftSum, rightSum);
        int up = root ->  val + leftSum + rightSum;
        maxSum = max({maxSum, down, up, root -> val});
        return max(root -> val, down);

        // if (leftSum < rightSum) {
        //     if (leftSum + root -> val > 0) {
        //         maxSum = max(maxSum, leftSum + root -> val + rightSum);
        //         maxSum = max(maxSum, leftSum);
        //     } else {
        //         maxSum = max(maxSum, rightSum);
        //     }
        // } else {
        //     if (rightSum + root -> val > 0) {
        //         maxSum = max(maxSum, rightSum + root -> val + leftSum);
        //         maxSum = max(maxSum, rightSum);
        //     } else {
        //         maxSum = max(maxSum, leftSum);
        //     }
        // }

        // return max(leftSum + root -> val, rightSum + root -> val);
    }
    int maxPathSum(TreeNode* root) {
        solve(root);
        return maxSum;
    }
};