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
    TreeNode* getSuccessor(TreeNode* root) {
        while (root -> left) {
            root = root -> left;
        }
        return root;
    }
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        if (!root) {
            return root;
        }
        root -> left = deleteNode(root -> left, key);
        root -> right = deleteNode(root -> right, key);
        if (root -> val == key) {
            if (root -> left && root -> right) {
                TreeNode* successor = getSuccessor(root -> right);
                swap(root -> val, successor -> val);
                deleteNode(root, successor -> val);
            } else if (root -> left) {
                TreeNode* node = root -> left;
                root -> left = nullptr;
                delete(root);
                return node;
            } else if (root -> right) {
                TreeNode* node = root -> right;
                root -> right = nullptr;
                delete(root);
                return node;
            } else {
                delete(root);
                return nullptr;
            }
        }

        return root;
    }
};