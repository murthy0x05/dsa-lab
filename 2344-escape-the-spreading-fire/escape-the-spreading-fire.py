import copy

class Solution:
    def maximumMinutes(self, grid: List[List[int]]) -> int:
        self.R, self.C = len(grid), len(grid[0])

        Q = deque()
        V = [[False for _ in range(self.C)] for _ in range(self.R)]

        dir = [-1, 0, 1, 0, -1]
        for i in range(self.R):
            for j in range(self.C):
                if grid[i][j] == 1:
                    V[i][j] = True
                    Q.append((i, j))
        def feasible(STAY):
            q = copy.deepcopy(Q)
            visited = copy.deepcopy(V)


            level = 0
            while q and level < STAY:
                for _ in range(len(q)):
                    i, j = q[0]
                    q.popleft()

                    for d in range(4):
                        ni, nj = dir[d] + i, dir[d + 1] + j
                        if 0 <= ni < self.R and 0 <= nj < self.C and not visited[ni][nj] and grid[ni][nj] == 0:
                            visited[ni][nj] = True
                            q.append((ni, nj))

                level += 1

            p = None
            pvisited = [[False for _ in range(self.C)] for _ in range(self.R)]
            if not visited[0][0]:
                pvisited[0][0] = True
                p = deque([(0, 0)])
            while p:
                for _ in range(len(q)):
                    i, j = q[0]
                    q.popleft()

                    for d in range(4):
                        ni, nj = dir[d] + i, dir[d + 1] + j
                        if 0 <= ni < self.R and 0 <= nj < self.C and not visited[ni][nj] and grid[ni][nj] == 0:
                            if ni == self.R - 1 and nj == self.C - 1:
                                if pvisited[self.R - 2][self.C - 1] or pvisited[self.R - 1][self.C - 2]:
                                    return True
                            visited[ni][nj] = True
                            q.append((ni, nj))
                
                for _ in range(len(p)):
                    i, j = p[0]
                    p.popleft()
                    if i == self.R - 1 and j == self.C - 1:
                        return True
                    
                    for d in range(4):
                        ni, nj = dir[d] + i, dir[d + 1] + j
                        if 0 <= ni < self.R and 0 <= nj < self.C and not visited[ni][nj] and not pvisited[ni][nj] and grid[ni][nj] == 0:
                            pvisited[ni][nj] = True
                            p.append((ni, nj))

                level += 1
                       
            return False
        
        low, high = 0, 10 ** 9
        result = -1
        while low <= high:
            mid = low + ((high - low) >> 1)
            if feasible(mid):
                result = mid
                low = mid + 1
            else:
                high = mid - 1
        
        return result