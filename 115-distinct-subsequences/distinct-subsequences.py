class Solution:
    def numDistinct(self, s: str, t: str) -> int:
        N1, N2 = len(s), len(t)

        dp = [[0 for _ in range(N2 + 1)] for _ in range(N1 + 1)]

        # dp[i][j] = no. of distinct subsequences in s[0:i] and t[0:j]

        for i in range(N1 + 1):
            dp[i][0] = 1

        for i in range(N1):
            for j in range(N2):
                dp[i + 1][j + 1] += dp[i][j + 1]
                if s[i] == t[j]:
                    dp[i + 1][j + 1] += dp[i][j]
        
        return dp[-1][-1]