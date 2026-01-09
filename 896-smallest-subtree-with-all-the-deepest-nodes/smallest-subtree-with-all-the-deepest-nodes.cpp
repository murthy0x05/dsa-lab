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
    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        function<pair<TreeNode*, int>(TreeNode*, int)> dfs = [&](TreeNode* node, int len) {
            pair<TreeNode*, int> left, right;
            left = right = make_pair(node, len);

            if (node -> left)
                left = dfs(node -> left, len + 1);
            if (node -> right)
                right = dfs(node -> right, len + 1);

            if (left.second == right.second) {
                return make_pair(node, left.second);
            }
            if (left.second > right.second) {
                return left;
            }
            return right;
        };
        return dfs(root, 0).first;
    }
};