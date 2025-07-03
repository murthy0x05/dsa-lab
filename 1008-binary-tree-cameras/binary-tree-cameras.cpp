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
    int solve(TreeNode* root) {
        if (root == nullptr) {
            return 1;
        }

        int left = solve(root -> left);
        int right = solve(root -> right);

        if (left == 0 || right == 0) {
            cameras += 1;
            return 2;
        }
        if (left == 2 || right == 2) {
            return 1;
        }

        return 0;
    }
public:
    int minCameraCover(TreeNode* root) {
        if (solve(root) == 0) {
            return cameras + 1;
        } else {
            return cameras;
        }
    }
};

/*
 * Here, each node can be defined as one of 3 types:
 * type 0: No camera, Not being watched.
 * type 1: No camera, being watched.
 * type 2: Camera, so begin watched(trivial).
 */