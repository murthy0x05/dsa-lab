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
        string code;
        function<void(TreeNode*)> serialize = [&] (TreeNode* node) {
            code += to_string(node -> val);

            if (!node -> left && !node -> right) 
                return ;

            code.push_back('(');
            if (node -> left) {
                serialize(node -> left);
            }
            code.push_back(')');

            if (node -> right) {
                code.push_back('(');
                serialize(node -> right);
                code.push_back(')');
            }
        };

        serialize(root);
        return code;
    }
};