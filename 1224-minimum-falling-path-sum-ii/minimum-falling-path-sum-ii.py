class Solution:
    def minFallingPathSum(self, grid: list[list[int]]) -> int:
        R, C = len(grid), len(grid[0])

        prev = grid[0][:]
        for i in range(1, R):
            curr = [0 for _ in range(C)]

            for j in range(C):
                smallest = float('inf')
                for k in range(C):
                    if j != k:
                        smallest = min(smallest, prev[k])

                curr[j] = grid[i][j] + smallest
            
            prev = curr
        
        return min(prev)