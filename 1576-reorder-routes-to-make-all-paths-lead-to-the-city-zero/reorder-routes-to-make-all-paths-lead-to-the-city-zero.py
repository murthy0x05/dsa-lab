class Solution:
    def minReorder(self, n: int, connections: List[List[int]]) -> int:
        V = n

        adj = [[] for _ in range(V)]
        for u, v in connections:
            adj[u].append((v, True))
            adj[v].append((u, False))
        
        self.result = 0
        def dfs (u, parent):
            for v, hasEdge in adj[u]:
                if v == parent:
                    continue
                if hasEdge:
                    self.result += 1
                
                dfs(v, u)
        
        dfs(0, -1)
        return self.result