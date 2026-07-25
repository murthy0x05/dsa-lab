class Solution:
    def maxProduct(self, n: int) -> int:
        X = sorted(str(n), reverse=True)
        return int(X[0]) * int(X[1])