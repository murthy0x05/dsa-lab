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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        const int N = postorder.size();
        map<int, int> id;
        for (int i = 0; i < N; i++) {
            id[inorder[i]] = i;
        }

        int i = N - 1;
        function<TreeNode*(int, int)> build = [&] (int low, int high) {
            if (low > high) {
                return (TreeNode*) nullptr;
            }

            TreeNode* node = new TreeNode(postorder[i]); i--;
            node -> right = build(id[node -> val] + 1, high);
            node -> left = build(low, id[node -> val] - 1);

            return node;
        };

        return build(0, N - 1);
    }
};