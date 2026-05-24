from collections import deque

class Solution:
    def maxJumps(self, arr: List[int], d: int) -> int:
        N = len(arr)
        
        mem = [-1 for _ in range(N)]
        def dfs(i):
            if mem[i] != -1:
                return mem[i]
            visited = 1

            for j in range(i + 1, min(i + d + 1, N)):
                if arr[j] >= arr[i]:
                    break
                visited = max(visited, dfs(j) + 1)
            for j in range(i - 1, max(i - d - 1, -1), -1):
                if arr[j] >= arr[i]:
                    break
                visited = max(visited, dfs(j) + 1)
            
            mem[i] = visited
            return mem[i]
        
        maxVisited = 0
        for i in range(N):
            maxVisited = max(maxVisited, dfs(i))
        
        return maxVisited