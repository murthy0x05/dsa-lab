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
    long long result = 0LL;
    const int MOD = 1e9 + 7;
    int sumup(TreeNode* node) {
        if (!node) return 0;
        else return node -> val + sumup(node -> left) + sumup(node -> right);
    }
    int dfs(TreeNode* node, int& total) {
        int leftSum = 0, rightSum = 0;
        if (node -> left) {
            leftSum = dfs(node -> left, total);
            result = max(result, ((total - leftSum) * 1LL * leftSum));
        }
        if (node -> right) {
            rightSum = dfs(node -> right, total);
            result = max(result, ((total - rightSum) * 1LL * rightSum));
        }
        
        return node -> val + leftSum + rightSum;
    }
public:
    int maxProduct(TreeNode* root) {
        int sum = sumup(root);
        dfs(root, sum);

        return result % MOD;
    }
};