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
    int i = 0, N;
    TreeNode* buildBST(vector<int>& preorder, int low, int high) {
        if (i == N || preorder[i] < low || preorder[i] > high) {
            return (TreeNode*) nullptr;
        }

        TreeNode* node = new TreeNode(preorder[i]); i++;
        node -> left = buildBST(preorder, low, node -> val - 1);
        node -> right = buildBST(preorder, node -> val + 1, high);
        return node;
    }
public:
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        N = preorder.size();
        return buildBST(preorder, 0, 1001);
    }
};