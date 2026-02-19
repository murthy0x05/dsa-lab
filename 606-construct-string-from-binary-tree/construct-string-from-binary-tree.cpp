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
    string tree2str(TreeNode* root) {
        function<string(TreeNode*)> serialize = [&] (TreeNode* node) {
            string code = to_string(node -> val);

            if (!node -> left && !node -> right) 
                return code;

            code.push_back('(');
            if (node -> left) {
                code += serialize(node -> left);
            }
            code.push_back(')');

            if (node -> right) {
                code.push_back('(');
                code += serialize(node -> right);
                code.push_back(')');
            }

            return code;
        };

        return serialize(root);
    }
};