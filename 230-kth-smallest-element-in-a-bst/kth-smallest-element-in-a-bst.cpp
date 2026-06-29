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
    int kthSmallest(TreeNode* root, int k) {
        int K = k;
        function<int(TreeNode*)> f = [&] (TreeNode* node) {
            if (!node) {
                return -1;
            }

            int left = f(node -> left);
            if (left >= 0) {
                return left;
            }
                        
            K--;
            if (K == 0) {
                return node -> val;
            }
            
            int right = f(node -> right);
            if (right >= 0) {
                return right;
            }

            return -1;
        };

        return f(root);
    }
};