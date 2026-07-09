class Solution:
    def pathExistenceQueries(self, V: int, nums: List[int], maxDiff: int, queries: List[List[int]]) -> List[bool]:
        exts = [0 for _ in range(V)]
        
        for i in range(1, V):
            exts[i] = exts[i - 1] if nums[i] - nums[i - 1] <= maxDiff else i
        
        result = []
        for q in queries:
            result.append(exts[q[1]] <= q[0] if q[0] < q[1] else exts[q[0]] <= q[1])
    
        return result