/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
class Solution {
    int cameras = 0;
    private int solve(TreeNode root) {
        if (root == null) {
            return 2;
        }

        int left = solve(root.left);
        int right = solve(root.right);

        if (left == 1 || right == 1) {
            cameras += 1;
            return 0;
        } else if (left == 0 || right == 0) {
            return 2;
        } else {
            return 1;
        }
    }
    public int minCameraCover(TreeNode root) {
        if (solve(root) == 1) {
            return cameras + 1;
        }
        return cameras;
    }
}