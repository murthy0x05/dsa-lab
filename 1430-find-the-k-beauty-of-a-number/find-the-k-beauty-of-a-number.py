class Solution:
    def divisorSubstrings(self, num: int, k: int) -> int:
        N = str(num)

        beauty = 0
        for i in range(k - 1, len(N)):
            val = int(N[(i - k + 1):(i + 1)])
            if val == 0:
                continue
            
            if num % val == 0:
                beauty += 1
            
        return beauty   