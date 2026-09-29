from functools import cache

class Solution:
    def hasValidPath(self, grid: list[list[str]]) -> bool:
        self.R, self.C = len(grid), len(grid[0])
        
        @cache
        def f (i, j, diff):
            if (not (0 <= i < self.R)) or (not (0 <= j < self.C)):
                return False
            if diff < 0:
                return False

            if grid[i][j] == '(':
                diff += 1
            else:
                diff -= 1

            if i == self.R - 1 and j == self.C - 1:
                return diff == 0
            
            return f(i, j + 1, diff) or f(i + 1, j, diff)

        return f (0, 0, 0)