class Solution:
    def latestDayToCross(self, row: int, col: int, cells: List[List[int]]) -> int:
        self.R, self.C = row, col

        dir = [-1, 0, 1, 0, -1]
        def feasible(DAY):
            mat = [[0 for _ in range(self.C)] for _ in range(self.R)]

            for i in range(DAY):
                mat[cells[i][0] - 1][cells[i][1] - 1] = 1
            
            q = deque([])
            for j in range(self.C):
                if mat[0][j] == 0:
                    mat[0][j] = 2
                    q.append((0, j))
            
            while q:
                i, j = q.popleft()
                if i == self.R - 1:
                    return True

                for d in range(4):
                    ni, nj = i + dir[d], j + dir[d + 1]
                    if 0 <= ni < self.R and 0 <= nj < self.C and mat[ni][nj] == 0:
                        mat[ni][nj] = 2
                        q.append((ni, nj))
            
            return False

        low, high = 0, len(cells)
        while low <= high:
            mid = low + ((high - low) >> 1)
            if feasible(mid):
                low = mid + 1
            else:
                high = mid - 1
        
        return high