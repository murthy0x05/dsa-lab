class Solution:
    def numberOfSubmatrices(self, grid: List[List[str]]) -> int:
        R, C = len(grid), len(grid[0])

        count = 0
        ps = [[[0, 0] for _ in range(C + 1)] for _ in range(R + 1)]
        for i in range(R):
            for j in range(C):
                ps[i + 1][j + 1][0] = ps[i + 1][j][0] + ps[i][j + 1][0] - ps[i][j][0] + (grid[i][j] == 'X')
                ps[i + 1][j + 1][1] = ps[i + 1][j][1] + ps[i][j + 1][1] - ps[i][j][1] + (grid[i][j] == 'Y')
                if (ps[i + 1][j + 1][0] > 0 and ps[i + 1][j + 1][0] == ps[i + 1][j + 1][1]):
                    count += 1

        return count