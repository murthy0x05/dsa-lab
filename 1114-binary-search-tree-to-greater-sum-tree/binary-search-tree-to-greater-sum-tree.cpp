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
    TreeNode* bstToGst(TreeNode* root) {
        function<pair<TreeNode*, int>(TreeNode*, int)> dfs = [&](TreeNode* bst, int val) {
            if (!bst) {
                return make_pair((TreeNode*)nullptr, 0);
            }

            TreeNode* gst = new TreeNode(bst -> val);

            pair<TreeNode*, int> right = dfs(bst -> right, val);
            gst -> right = right.first;
            gst -> val += right.second;
            gst -> val += val;

            pair<TreeNode*, int> left = dfs(bst -> left, gst -> val);
            gst -> left = left.first;

            return make_pair(gst, bst -> val + left.second + right.second);
        };
        
        int total = 0;
        function<void(TreeNode*)> po = [&](TreeNode* bst) {
            if (!bst) {
                return ;
            }

            po(bst -> right);
            bst -> val = (total += bst -> val);
            po(bst -> left);
        };

        int sum = 0;
        function<TreeNode*(TreeNode*)> post = [&](TreeNode* bst) {
            if (!bst) {
                return (TreeNode*) nullptr;
            }

            TreeNode* gst = new TreeNode();

            gst -> right = post(bst -> right);
            gst -> val = (sum += bst -> val);
            gst -> left = post(bst -> left);

            return gst;
        };

        // return dfs(root, 0).first;
        // po(root);

        return post(root);
    }
};