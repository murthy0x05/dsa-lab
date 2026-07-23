class Solution:
    def colorBorder(self, grid: List[List[int]], row: int, col: int, color: int) -> List[List[int]]:
        self.R, self.C = len(grid), len(grid[0])
        self.COLOR = color

        visited = [[False for _ in range(self.C)] for _ in range(self.R)]
        dir = [-1, 0, 1, 0, -1]
        def dfs(i, j):
            visited[i][j] = True
            
            D = 0
            for d in range(4):
                ni, nj = dir[d] + i, dir[d + 1] + j
                if 0 <= ni < self.R and 0 <= nj < self.C:
                    if not visited[ni][nj]:
                        if grid[ni][nj] == grid[i][j]:
                            dfs(ni, nj)
                            D += 1
                    else:
                        D += 1
            if D < 4:
                grid[i][j] = self.COLOR
        
        dfs(row, col)
        return grid
            
