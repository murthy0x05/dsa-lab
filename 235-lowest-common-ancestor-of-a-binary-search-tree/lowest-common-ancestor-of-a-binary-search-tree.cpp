/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
    #define Node TreeNode
    Node* solve(Node* root, Node* p, Node* q) {
        if (root == nullptr || root == p || root == q) {
            return root;
        }

        Node* left = nullptr;
        Node* right = nullptr;
        if (root -> val < p -> val) {
            right = solve(root -> right, p, q);
        } else {
            left = solve(root -> left, p, q);
        }
        
        if (root -> val < q -> val) {
            right = solve(root -> right, p, q);
        } else {
            left = solve(root -> left, p, q);
        }

        if (left && right)
            return root;
        else
            return left ? left : right;
    }
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        return solve(root, p, q);
    }
};