from collections import deque

class Solution:
    def maximumSafenessFactor(self, grid: List[List[int]]) -> int:
        R, C = len(grid), len(grid[0])

        level = 0
        dq = deque()
        visited = [[False for _ in range(C)] for _ in range(R)]
        dist = [[0 for _ in range(C)] for _ in range(R)]
        for i in range(R):
            for j in range(C):
                if grid[i][j] == 1:
                    dist[i][j] = 0
                    visited[i][j] = True
                    dq.append((i, j))
        
        level += 1
        dir = [-1, 0, 1, 0, -1]
        while dq:
            for ls in range(len(dq)):
                i, j = dq.popleft()
                for d in range(4):
                    ni, nj = i + dir[d], j + dir[d + 1]
                    if ni >= 0 and nj >= 0 and ni < R and nj < C and not visited[ni][nj]:
                        dist[ni][nj] = level
                        visited[ni][nj] = True
                        dq.append((ni, nj))
            level += 1
        
        def feasible(M):
            visited = [[False for _ in range(C)] for _ in range(R)]
            
            def dfs(i, j):
                if i == R - 1 and j == C - 1:
                    return True

                visited[i][j] = True
                for d in range(4):
                    ni, nj = i + dir[d], j + dir[d + 1]
                    if ni >= 0 and nj >= 0 and ni < R and nj < C and not visited[ni][nj] and dist[ni][nj] >= M:
                        if (dfs(ni, nj)):
                            return True
                
                return False
            
            if dist[0][0] >= M:
                return dfs(0, 0)
            else:
                return False

        l, r = 0, R + C - 2
        while l <= r:
            m = l + ((r - l) >> 1)
            if feasible(m):
                l = m + 1
            else:
                r = m - 1
        
        return r