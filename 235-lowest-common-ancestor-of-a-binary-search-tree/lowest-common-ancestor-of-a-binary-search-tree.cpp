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
        Node* node = root;
        while (node) {
            if (node -> val < p -> val && node -> val < q -> val)
                node = node -> right;
            else if (node -> val > p -> val && node -> val > q -> val)
                node = node -> left;
            else
                return node;
        }

        return nullptr;
    }
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        return solve(root, p, q);
    }
};