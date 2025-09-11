import math

class SegmentTree:
    left = lambda self, node: 2 * node + 1
    right = lambda self, node: 2 * node + 2
    def _build(self, arr: List[int], node: int, start: int, end: int):
        if start == end:
            self.tree[node] = arr[start]
        else:
            mid = start + ((end - start) >> 1)
            self._build(arr, self.left(node), start, mid)
            self._build(arr, self.right(node), mid + 1, end)
            self.tree[node] = max(self.tree[self.left(node)], self.tree[self.right(node)])
    
    def __init__(self, arr, n):
        self.n = n
        size = 2 * (pow(2, ceil(log2(n)))) - 1
        self.tree = [0] * size
        self._build(arr, 0, 0, n - 1)

    def _nge(self, node, start, end, l, r, val) -> int:
        if start > r or end < l:
            return -1
        elif self.tree[node] <= val:
            return -1
        elif start == end:
            return start
        else:
            mid = start + ((end - start) >> 1)
            res = self._nge(self.left(node), start, mid, l, r, val)
            if res != -1:
                return res
            else:
                return self._nge(self.right(node), mid + 1, end, l, r, val)   
    def nge(self, l, r, val) -> int:
        return self._nge(0, 0, self.n - 1, l, r, val)

class Solution:
    def leftmostBuildingQueries(self, heights: List[int], queries: List[List[int]]) -> List[int]:
        n = len(heights)
        q = len(queries)

        result = []
        segTree = SegmentTree(heights, n)

        for a, b in queries:
            if a == b:
                result.append(a)
            elif a < b and heights[a] < heights[b]:
                result.append(b)
            elif a > b and heights[a] > heights[b]:
                result.append(a)
            else:
                result.append(segTree.nge(max(a, b) + 1, n - 1, max(heights[a], heights[b])))
        
        return result