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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        const int N = preorder.size();
        map<int, int> id;
        for (int i = 0; i < N; i++) {
            id[inorder[i]] = i;
        }
        
        int i = 0;
        function<TreeNode*(int, int)> build = [&](int low, int high) {
            if (low > high) {
                return (TreeNode*) nullptr;
            }

            TreeNode* node = new TreeNode(preorder[i]); i++;
            node -> left = build(low, id[node -> val] - 1);
            node -> right = build(id[node -> val] + 1, high);

            return node;
        };

        return build(0, N - 1);

    }
};