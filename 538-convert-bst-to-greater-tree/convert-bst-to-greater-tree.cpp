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
    TreeNode* convertBST(TreeNode* root) {
        int total = 0;
        function<void(TreeNode*)> dfs = [&](TreeNode* bst) {
            if (bst) {
                dfs(bst -> right);

                total += bst -> val;
                bst -> val = total;
                
                dfs(bst -> left);
            }
        };

        dfs(root);
        return root;
    }
};