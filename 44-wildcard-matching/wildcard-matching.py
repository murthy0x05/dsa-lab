class Solution:
    def isMatch(self, s: str, p: str) -> bool:
        N1 = len(s)
        N2 = len(p)

        # @cache
        # def f (i, j):
        #     if j == N2:
        #         return i == N1
        #     if i == N1:
        #         return all([c == '*' for c in p[j:]])

        #     if p[j] == '*':
        #         return f(i + 1, j + 1) or f(i + 1, j) or f(i, j + 1)
        #     elif p[j] == '?':
        #         return f(i + 1, j + 1)
        #     else:
        #         return p[j] == s[i] and f(i + 1, j + 1)

        dp = [[False for j in range(N2 + 1)] for i in range(N1 + 1)]
        dp[0][0] = True

        for j in range(1, N2 + 1):
            dp[0][j] = all([c == '*' for c in p[:j]])

        for i in range(N1):
            for j in range(N2):
                if p[j] == '?':
                    dp[i + 1][j + 1] = dp[i][j]
                elif p[j] == '*':
                    dp[i + 1][j + 1] = dp[i + 1][j] or dp[i][j + 1] or dp[i][j]
                else:
                    dp[i + 1][j + 1] = dp[i][j] and s[i] == p[j]
        
        # print(end = '    ')
        # for j in range(N2):
        #     print(p[j], end = ' ')
        # print()
        # for i in range(N1 + 1):
        #     if i >= 1:
        #         print(s[i - 1], end = ' ')
        #     else:
        #         print(end = '  ')
        #     for j in range(N2 + 1):
        #         print('T' if dp[i][j] else 'F', end = ' ')
        #     print()

        return dp[-1][-1]