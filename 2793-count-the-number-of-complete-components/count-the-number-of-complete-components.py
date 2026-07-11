class Solution:
    def countCompleteComponents(self, n: int, edges: List[List[int]]) -> int:
        adj = [[] for _ in range(n)]

        for u, v in edges:
            adj[u].append(v)
            adj[v].append(u)
        
        visited = [False for _ in range(n)]
        def dfs(node):
            V, E = 0, len(adj[node])
            visited[node] = True
            for nbr in adj[node]:
                if not visited[nbr]:
                    Vr, Er = dfs(nbr)
                    V, E = V + Vr, E + Er

            return (1 + V, E)
        
        comp = 0
        for i in range(n):
            if not visited[i]:
                V, E = dfs(i)
                if (V * (V - 1))== E:
                    comp += 1
            
        return comp