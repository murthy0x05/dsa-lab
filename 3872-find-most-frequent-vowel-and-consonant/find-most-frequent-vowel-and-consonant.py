class Solution:
    def maxFreqSum(self, s: str) -> int:
        counts = [0] * 26

        for c in s:
            counts[ord(c) - 97] += 1
        
        mv, mc = float('-inf'), float('-inf')
        for i in range(26):
            if (i == 97 - 97 or i == ord('e') - 97 or i == ord('i') - 97 or i == ord('o') - 97 or i == ord('u') - 97):
                mv = max(mv, counts[i])
            else:
                mc = max(mc, counts[i])
            
        return mv + mc