class Solution:
    def pacificAtlantic(self, heights: List[List[int]]) -> List[List[int]]:
        self.R, self.C = len(heights), len(heights[0])
        
        dir = [-1, 0, 1, 0, -1]
        def dfs(i, j, visited):
            visited[i][j] = True

            for d in range(4):
                ni, nj = i + dir[d], j + dir[d + 1]
                if 0 <= ni < self.R and 0 <= nj < self.C and not visited[ni][nj] and heights[ni][nj] >= heights[i][j]:
                    dfs(ni, nj, visited)
        
        atlantic = [[False for _ in range(self.C)] for _ in range(self.R)]
        pacific = [[False for _ in range(self.C)] for _ in range(self.R)]
        for i in range(self.R):
            if not pacific[i][0]:
                dfs(i, 0, pacific)
            if not atlantic[i][self.C - 1]:
                dfs(i, self.C - 1, atlantic)
        for j in range(self.C):
            if not pacific[0][j]:
                dfs(0, j, pacific)
            if not atlantic[self.R - 1][j]:
                dfs(self.R - 1, j, atlantic)
        
        result = []
        for i in range(self.R):
            for j in range(self.C):
                if atlantic[i][j] and pacific[i][j]:
                    result.append([i, j])
        
        return result