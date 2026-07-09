class Solution:
    def pathExistenceQueries(self, n: int, nums: List[int], maxDiff: int, queries: List[List[int]]) -> List[bool]:
        V = n

        exts = [0 for _ in range(V)]
        
        for i in range(1, V):
            if nums[i] - nums[i - 1] <= maxDiff:
                exts[i] = exts[i - 1]
            else:
                exts[i] = i
        
        result = []
        for query in queries:
            if query[0] < query[1]:
                result.append(True if exts[query[1]] <= query[0] else False)
            else:
                result.append(True if exts[query[0]] <= query[1] else False)
    
        return result