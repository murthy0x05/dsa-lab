# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def averageOfSubtree(self, root: TreeNode) -> int:
        self.cnt = 0
        def f(node):
            if not node:
                return (0, 0)

            L = f(node.left)
            R = f(node.right)

            result = (L[0] + R[0] + node.val, L[1] + R[1] + 1)

            if result[0] // result[1] == node.val:
                self.cnt += 1
            
            return result

        f(root)
        return self.cnt