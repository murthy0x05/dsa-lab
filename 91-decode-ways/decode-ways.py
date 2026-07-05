class Solution:
    def numDecodings(self, s: str) -> int:
        N = len(s)

        dp = [0 for _ in range(N + 1)]
        dp[0] = 1
        dp[1] = 1 if not s[0] == '0' else 0
        for i in range(1, N):
            if not s[i] == '0':
                dp[i + 1] = dp[i]
            if not s[i - 1] == '0':
                if int(s[(i - 1):(i + 1)]) <= 26:
                    dp[i + 1] += dp[i - 1]
        
        return dp[-1]