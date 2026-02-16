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
    using ui = unsigned int;
public:
    int widthOfBinaryTree(TreeNode* root) {
        vector<vector<ui>> widths;

        function<void(TreeNode*, int, ui)> dfs = [&] (TreeNode* node, int x, ui id) {
            if (!node) {
                return ;
            }

            if (widths.size() == x) {
                widths.push_back({id, id});
            } else {
                widths[x][0] = min<ui>(widths[x][0], id);
                widths[x][1] = max<ui>(widths[x][1], id);
            }

            dfs(node -> left, x + 1, 2 * id + 1);
            dfs(node -> right, x + 1, 2 * id + 2);
        };

        dfs(root, 0, (ui)0);
        int maxWidth = 0;
        for (vector<ui>& width: widths) {
            maxWidth = max<ui>(maxWidth, width[1] - width[0] + 1);
        }

        return maxWidth;
    }
};