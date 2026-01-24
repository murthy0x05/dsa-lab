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
    int dfs_left(TreeNode* node) {
        if (!node) {
            return 0;
        } else {
            return 1 + dfs_left(node -> left);
        }
    }
    int dfs_right(TreeNode* node) {
        if (!node) {
            return 0;
        } else {
            return 1 + dfs_right(node -> right);
        }
    }
public:
    int countNodes(TreeNode* root) {
        if (!root) {
            return 0;
        }

        int left_ht = dfs_left(root -> left);
        int right_ht = dfs_right(root -> right);

        if (left_ht == right_ht) {
            return (2 << left_ht) - 1;
        } else {
            return 1 + countNodes(root -> left) + countNodes(root -> right);
        }
    }

};