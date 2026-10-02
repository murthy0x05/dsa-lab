class Solution:
    def minFallingPathSum(self, grid: list[list[int]]) -> int:
        R, C = len(grid), len(grid[0])

        prev = grid[0][:]
        for i in range(1, R):
            prev = [grid[i][j] + min(prev[:j] + prev[(j + 1):]) for j in range(C)]
        
        return min(prev)