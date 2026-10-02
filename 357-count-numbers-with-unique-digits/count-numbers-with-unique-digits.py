class Solution:
    def countNumbersWithUniqueDigits(self, n: int) -> int:
        result = 1

        for i in range(1, n + 1):
            D = 9
            for j in range(i - 1):
                D *= 9 - j
            
            result += D
        
        return result

