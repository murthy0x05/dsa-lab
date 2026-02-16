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
    bool isCousins(TreeNode* root, int x, int y) {
        bool onSameLevel = false;
        function<int(TreeNode*)> dfs = [&] (TreeNode* node) {
            if (!node) {
                return -1;
            }

            if (node -> val == x) 
                return x = 0;
            if (node -> val == y)
                return y = 0;

            int l = dfs(node -> left);
            int r = dfs(node -> right);

            if (l == -1 && r == -1)
                return -1;
            if (l == -1)
                return r + 1;
            if (r == -1)
                return l + 1;
            if (l == r) {
                onSameLevel = l != 0;
                return l + 1;
            }

            return -1;
        };

        dfs(root);
        return onSameLevel;
    }
};