class Solution:
    def largestPalindrome(self, n: int) -> int:
        if (n == 1): return 9
        low, high = 10 ** (n - 1), 10 ** (n) - 1

        for i in range(high, low, -1):
            temp = str(i) + str(i)[::-1]
            p, j = int(temp), high
            while j * j >= p:
                if p % j == 0:
                    return p % 1337
                else:
                    j -= 1

        return 0            