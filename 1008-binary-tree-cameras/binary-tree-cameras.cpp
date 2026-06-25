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
    int cameras = 0;
    int f (TreeNode* node) {
        if (!node) {
            return 1;
        }
        if (!(node -> left) && !(node -> right)) {
            return 0;
        }

        int l = f(node -> left);
        int r = f(node -> right);

        if (l == 0 || r == 0) {
            cameras++;
            return 2;
        }
        if (l == 2 || r == 2) {
            return 1;
        }
        return 0;
    }
public:
    int minCameraCover(TreeNode* root) {

        // 3 states
        /*
            0 => not covered
            1 => covered
            2 => covered and has camera
        */
        if (f(root) == 0) {
            cameras++;
        }
        return cameras;


        
    }
};