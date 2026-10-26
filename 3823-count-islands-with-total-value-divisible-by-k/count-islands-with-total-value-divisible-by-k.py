class Solution:
    def countIslands(self, grid: List[List[int]], k: int) -> int:
        R, C = len(grid), len(grid[0])
        dir = [-1, 0, 1, 0, -1]
        def f(i, j):
            val = grid[i][j]
            grid[i][j] = 0
            for d in range(4):
                ni, nj = i + dir[d], j + dir[d + 1]

                if 0 <= ni < R and 0 <= nj < C and grid[ni][nj] > 0:
                    val += f(ni, nj)
            
            return val

        result = 0
        for i in range(R):
            for j in range(C):
                if grid[i][j] > 0:
                    result += 1 if f(i, j) % k == 0 else 0

        return result