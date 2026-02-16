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
            if (node -> val == x) {
                node -> val = 0;
                x = 0;
                return 0;
            }
            if (node -> val == y) {
                node -> val = 0;
                y = 0;
                return 0;
            }

            int left = dfs(node -> left);
            int right = dfs(node -> right);

            if (left == -1 || right == -1) {
                if (left != -1) {
                    return left + 1;
                } else if (right != -1) {
                    return right + 1;
                } else {
                    return -1;
                }
            }

            if (left == right) {
                if (node -> left -> val != node -> right -> val || node -> left -> val != 0) {
                    onSameLevel = true;
                }
            }

            return -1;
        };

        dfs(root);
        return onSameLevel;
    }
};