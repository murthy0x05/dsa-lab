class Solution:
    def minSumOfLengths(self, arr: List[int], target: int) -> int:
        N = len(arr)
        
        currSum = 0
        occ = {0: -1}
        lens = []
        for i in range(N):
            currSum += arr[i]
            occ[currSum] = i

            diff = currSum - target
            if diff in occ:
                lens.append((occ[diff] + 1, i))

        if len(lens) < 2:
            return -1

        lens.sort(key = lambda x: (x[1], x[0]))

        dp = [float('inf') for _ in range(N)]
        for l, r in lens:
            dp[r] = min(dp[r], r - l + 1)
        for i in range(1, N):
            dp[i] = min(dp[i], dp[i - 1])
        
        smallest = float('inf')
        for l, r in lens:
            if l > 0:
                smallest = min(smallest, r - l + 1 + dp[l - 1])
        print(dp)
        
        if smallest == float('inf'):
            return -1
        return smallest
