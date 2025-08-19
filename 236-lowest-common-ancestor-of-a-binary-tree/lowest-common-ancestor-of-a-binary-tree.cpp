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

        Node* left = solve(root -> left, p, q);
        Node* right = solve(root -> right, p, q);

        if (left == nullptr) {
            return right;
        } else if (right == nullptr) {
            return left;
        } else {
            return root;
        }
    }
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        return solve(root, p, q);
    }
};