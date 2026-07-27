import heapq

class Solution:
    def minimumWeight(self, n: int, edges: List[List[int]], src1: int, src2: int, dest: int) -> int:
        self.V, self.E = n, len(edges)
        self.dest = dest

        adj = [[] for _ in range(self.V)]
        for u, v, w in edges:
            adj[u].append((v, w))
        
        def djikstra(src):
            D = [float('inf') for _ in range(self.V)]

            D[src] = 0
            pq = [(0, src)]

            while pq:
                Dw, u = heapq.heappop(pq)

                if D[u] < Dw:
                    continue
                
                for v, w in adj[u]:
                    if D[v] > (D[u] + w):
                        D[v] = D[u] + w
                        heapq.heappush(pq, (D[v], v))
            
            return D


        D1 = djikstra(src1)
        D2 = djikstra(src2)

        adj = [[] for _ in range(self.V)]
        for v, u, w in edges:
            adj[u].append((v, w))
        D3 = djikstra(dest)

        smallest = min(D1[dest] + D2[dest], D1[src2] + D2[dest], D2[src1] + D1[dest])
        print("src1 -> dest", D1[dest])
        print("src2 -> dest", D1[dest])
        print(D1[src2] + D2[dest])
        print(D2[src1] + D1[dest])
        for i in range(self.V):
            smallest = min(smallest, D1[i] + D2[i] + D3[i])
        
        return smallest if smallest != float('inf') else -1
