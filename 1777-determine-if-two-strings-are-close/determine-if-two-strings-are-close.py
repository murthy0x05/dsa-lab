class Solution:
    def closeStrings(self, word1: str, word2: str) -> bool:
        N1, N2 = len(word1), len(word2)
        if not N1 == N2:
            return False
    
        f1 = [0 for _ in range(26)]
        f2 = [0 for _ in range(26)]
        
        for i in range(N1):
            f1[ord(word1[i]) - ord('a')] += 1
            f2[ord(word2[i]) - ord('a')] += 1
        
        # for i in range(26):
        #     if (f1[i] > 0) ^ (f2[i] > 0):
        #         return False
        
        return set(word1) == set(word2) and sorted(f1) == sorted(f2)