class Solution:
    def kthSmallest(self, matrix: List[List[int]], k: int) -> int:
        R, C = len(matrix), len(matrix[0])

        l, r = matrix[0][0], matrix[-1][-1]
        while l <= r:
            col = C - 1
            m = l + ((r - l) >> 1)
            K, Kth = 0, float('-inf')
            for row in range(R):
                while col >= 0 and matrix[row][col] > m:
                    col -= 1
                
                K += col + 1
                if col >= 0:
                    Kth = max(Kth, matrix[row][col])

            if K == k:
                return Kth
            elif K < k:
                l = m + 1
            else:
                r = m - 1
        
        return l

