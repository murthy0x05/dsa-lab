class Solution:
    def climbStairs(self, n: int, costs: List[int]) -> int:
        dp = [0 for _ in range(n + 1)]

        for i in range(1, n + 1):
            if i - 1 >= 0:
                dp[i] = dp[i - 1] + costs[i - 1] + 1
            if i - 2 >= 0:
                dp[i] = min(dp[i], dp[i - 2] + costs[i - 1] + 4)
            if i - 3 >= 0:
                dp[i] = min(dp[i], dp[i - 3] + costs[i - 1] + 9)

        return dp[-1]