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
    int sumRootToLeaf(TreeNode* root) {
        
        function<int(TreeNode*, int)> dfs = [&] (TreeNode* node, int val) {
            val = (val << 1) | node -> val;
            
            if (node -> left && node -> right) {
                return dfs(node -> left, val) + dfs(node -> right, val);
            } else if (node -> left) {
                return dfs(node -> left, val);
            } else if (node -> right) {
                return dfs(node -> right, val);
            } else {
                return val;
            }
        };

        return dfs(root, 0);
    }
};