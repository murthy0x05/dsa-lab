class Solution:
    def countCommas(self, n: int) -> int:
        base = 1

        result = 0
        while base <= n:
            base *= 1000
            result += max(0, n - base + 1)

        return result