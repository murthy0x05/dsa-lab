/*
// Definition for a Node.
class Node {
    public int val;
    public Node left;
    public Node right;
    public Node next;

    public Node() {}
    
    public Node(int _val) {
        val = _val;
    }

    public Node(int _val, Node _left, Node _right, Node _next) {
        val = _val;
        left = _left;
        right = _right;
        next = _next;
    }
};
*/

class Solution {
    public Node connect(Node root) {
        Queue<Node> q = new LinkedList<>();
        if (root != null)
            q.add(root);
        while (!q.isEmpty()) {
            int levelSize = q.size();
            Node curr = null;
            for (int i = 0; i < levelSize; i++) {
                curr = q.peek(); q.poll();
                if (i + 1 < levelSize) {
                    curr.next = q.peek();
                }
                if (curr.left != null) {
                    q.add(curr.left);
                }
                if (curr.right != null) {
                    q.add(curr.right);
                }
            }
            curr.next = null;
        }

        return root;
    }
}