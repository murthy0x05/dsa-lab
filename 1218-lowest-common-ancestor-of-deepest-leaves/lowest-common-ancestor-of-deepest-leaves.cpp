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
    TreeNode* lcaDeepestLeaves(TreeNode* root) {
        return solve(root).first;
    }
private:
    #define Node TreeNode
    #define pni pair<Node*, int>
    pni solve(Node* node) {
        if (node == nullptr) {
            return make_pair(nullptr, 0);
        }

        pni left = solve(node -> left);
        pni right = solve(node -> right);

        if (left.second > right.second) {
            return {left.first, left.second + 1};
        } else if (left.second < right.second) {
            return {right.first, right.second + 1};
        } else {
            return {node, left.second + 1};
        }
    }
};