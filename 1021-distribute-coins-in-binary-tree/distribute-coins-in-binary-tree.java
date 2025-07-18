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
    int moves = 0;
    private int doDFS(TreeNode root) {
        if (root == null) {
            return 0;
        }

        root.val += doDFS(root.left);
        root.val += doDFS(root.right);

        if (root.val == 0) {
            moves += 1;
            return -1;
        } else if (root.val > 1) {
            moves += root.val - 1;
            return root.val - 1;
        } else if (root.val < 0) {
            moves += Math.abs(root.val - 1);
            return root.val - 1;
        } else {
            return 0;
        }
    }
    public int distributeCoins(TreeNode root) {
        doDFS(root);
        return moves;
    }
}