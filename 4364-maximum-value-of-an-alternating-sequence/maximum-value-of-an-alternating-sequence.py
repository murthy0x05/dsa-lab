class Solution:
    def maximumValue(self, n: int, s: int, m: int) -> int:
        if n == 1:
            return s
        return (n >> 1) * (m - 1) + s + 1