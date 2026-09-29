from functools import cache

class Solution:
    def hasValidPath(self, grid: list[list[str]]) -> bool:
        self.R, self.C = len(grid), len(grid[0])
        
        @cache
        def f (i, j, o, c):
            if (not (0 <= i < self.R)) or (not (0 <= j < self.C)):
                return False
            if o < c:
                return False

            if grid[i][j] == '(':
                o += 1
            else:
                c += 1

            if i == self.R - 1 and j == self.C - 1:
                return o == c
            
            return f(i, j + 1, o, c) or f(i + 1, j, o, c)

        return f (0, 0, 0, 0)