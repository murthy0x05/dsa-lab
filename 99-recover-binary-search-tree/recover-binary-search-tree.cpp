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
    void recoverTree(TreeNode* root) {
        TreeNode* X = nullptr;
        TreeNode* Y = nullptr;

        TreeNode* prev = new TreeNode(INT_MIN);
        function<void(TreeNode*)> f = [&] (TreeNode* node) {
            if (!node) {
                return;
            }
 
            f(node -> left);

            if (prev -> val > node -> val) {
                if (!X) {
                    X = prev;
                }
                Y = node;
            }
            prev = node;

            f(node -> right);
        };

        f(root);
        if (X && Y) {
            swap(X -> val, Y -> val);
        }
    }
};