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
    TreeNode* balanceBST(TreeNode* root) {
        vector<int> inOrder;
        function<void(TreeNode*)> traverse = [&](TreeNode* node) {
            if (node) {
                traverse(node -> left);
                inOrder.push_back(node -> val);
                traverse(node -> right);
            }
        };
        traverse(root);

        function<TreeNode*(int, int)> dfs = [&](int low, int high) {
            if (low > high) {
                return (TreeNode*) nullptr;
            }
            if (low == high) {
                return new TreeNode(inOrder[low]);
            }

            int mid = low + ((high - low) >> 1);
            TreeNode* node = new TreeNode(inOrder[mid]);
            node -> left = dfs(low, mid - 1);
            node -> right = dfs(mid + 1, high);

            return node;
        };

        return dfs(0, inOrder.size() - 1);
    }
};