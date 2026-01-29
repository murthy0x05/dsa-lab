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
    int pathSum = -1001;
    int dfs(TreeNode* node) {
        if (!node) return 0;

        int left = max(0, dfs(node -> left));
        int right = max(0, dfs(node -> right));

        pathSum = max(pathSum, (left + node -> val + right));
        return max(left, right) + node -> val;
    }
public:
    int maxPathSum(TreeNode* root) {
        dfs(root);
        return pathSum;
    }
    
};