import heapq

class Solution:
    def shortestPath(self, n: int, edges: List[List[int]], labels: str, k: int) -> int:
        V = n
        adj = [[] for _ in range(V)]

        for u, v, w in edges:
            adj[u].append((v, w))

        pq = [(0, 1, 0)]
        D = [[float('inf') for _ in range(k + 1)] for _ in range(V)]
        D[0][1] = 0

        while pq:
            W, rep, u = heapq.heappop(pq)

            if D[u][rep] < W:
                continue
            
            for v, w in adj[u]:
                if labels[u] == labels[v]:
                    if rep + 1 <= k and W + w < D[v][rep + 1]:
                        D[v][rep + 1] = W + w
                        heapq.heappush(pq, (W + w, rep + 1, v))
                else:
                    if W + w < D[v][1]:
                        D[v][1] = W + w
                        heapq.heappush(pq, (W + w, 1, v))

        result = min(D[-1][:])
        if result == float('inf'):
            return -1
        
        return result