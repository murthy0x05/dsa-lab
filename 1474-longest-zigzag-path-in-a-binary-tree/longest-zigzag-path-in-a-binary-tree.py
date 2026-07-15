# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def longestZigZag(self, root: Optional[TreeNode]) -> int:
        self.longest = 0
        def f(node):
            if not node:
                return (-1, -1)
            
            l = f(node.left)
            r = f(node.right)
            self.longest = max(self.longest, *l, *r)

            return (l[1] + 1, r[0] + 1)
        
        return max(*f(root), self.longest)
            
