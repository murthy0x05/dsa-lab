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
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        const int N = preorder.size();
        int i = 0;
        function<TreeNode*(int, int)> buildBST = [&] (int low, int high) {
            if (i == N || preorder[i] < low || preorder[i] > high) {
                return (TreeNode*) nullptr;
            }

            TreeNode* node = new TreeNode(preorder[i]); i++;
            node -> left = buildBST(low, node -> val - 1);
            node -> right = buildBST(node -> val + 1, high);

            return node;
        };

        return buildBST(0, 1001);
    }
};