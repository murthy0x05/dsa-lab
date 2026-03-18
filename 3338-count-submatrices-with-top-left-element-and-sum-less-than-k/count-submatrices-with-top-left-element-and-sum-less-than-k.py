class Solution:
    def countSubmatrices(self, grid: List[List[int]], k: int) -> int:
        R, C = len(grid), len(grid[0])

        ps = [[0 for _ in range(C + 1)] for _ in range(R + 1)]
        for i in range(R):
            for j in range(C):
                ps[i + 1][j + 1] = ps[i][j + 1] + ps[i + 1][j] - ps[i][j] + grid[i][j]

        count = 0
        for i in range(R):
            for j in range(C):
                count += 1 if ps[i + 1][j + 1] <= k else 0
        
        return count