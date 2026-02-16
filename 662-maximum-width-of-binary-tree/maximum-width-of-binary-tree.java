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
    public int widthOfBinaryTree(TreeNode root) {
        class Box {
            public TreeNode node;
            public int id;
            public Box(TreeNode _node, int _id) {
                node = _node;
                id = _id;
            }
        }

        int maxWidth = 0;
        Deque<Box> q = new LinkedList<>();
        q.offerLast(new Box(root, 0));
        while (!q.isEmpty()) {
            maxWidth = Math.max(maxWidth, (q.peekLast().id) - (q.peekFirst().id) + 1);
            for (int ls = q.size(); ls > 0; ls--) {
                Box curr = q.pollFirst();
                if (curr.node.left != null) {
                    q.offerLast(new Box(curr.node.left, 2 * curr.id + 1));
                }
                if (curr.node.right != null) {
                    q.offerLast(new Box(curr.node.right, 2 * curr.id + 2));
                }
            }
        }

        return maxWidth;
    }
}