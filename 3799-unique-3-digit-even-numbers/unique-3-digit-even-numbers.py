from collections import Counter

class Solution:
    def totalNumbers(self, digits: List[int]) -> int:
        N = len(digits)

        result = 0
        occ = Counter(digits)
        for i in range(100, 1000, 2):
            S = str(i)
            for j in range(10):
                if occ[j] < S.count(chr(j + ord('0'))):
                    break
            else:
                result += 1
        
        return result