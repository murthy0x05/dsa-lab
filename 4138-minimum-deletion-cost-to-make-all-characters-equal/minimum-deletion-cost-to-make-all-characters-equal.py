class Solution:
    def minCost(self, s: str, cost: List[int]) -> int:
        N = len(cost)

        fc = {}
        for i in range(N):
            fc[s[i]] = fc.get(s[i], 0) + cost[i]

        total = sum(cost)
        smallest = float('inf')
        for c, charCost in fc.items():
            smallest = min(smallest, total - charCost)
        
        return smallest