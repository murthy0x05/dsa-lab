class Solution:
    def minDistance(self, word1: str, word2: str) -> int:
        N1, N2 = len(word1), len(word2)

        prev = [0 for _ in range(N2 + 1)]
        for i in range(1, N1 + 1):
            curr = [0 for _ in range(N2 + 1)]
            for j in range(1, N2 + 1):
                if word1[i - 1] == word2[j - 1]:
                    curr[j] = 1 + prev[j - 1]
                else:
                    curr[j] = max(prev[j], curr[j - 1])
            
            prev = curr
        
        return N1 - prev[-1] + N2 - prev[-1]