class Solution:
    def calculateMinimumHP(self, dungeon: List[List[int]]) -> int:
        R, C = len(dungeon), len(dungeon[0])

        dp = [[float('-inf') for _ in range(C)] for _ in range(R)]
        for i in range(R - 1, -1, -1):
            for j in range(C - 1, -1, -1):
                if i == R - 1 and j == C - 1:
                    dp[i][j] = min(0, dungeon[i][j])
                elif i == R - 1:
                    dp[i][j] = min(0, dungeon[i][j] + dp[i][j + 1])
                elif j == C - 1:
                    dp[i][j] = min(0, dungeon[i][j] + dp[i + 1][j])
                else:
                    dp[i][j] = min(0, dungeon[i][j] + max(dp[i + 1][j], dp[i][j + 1]))
        
        return -dp[0][0] + 1