class Solution:
    def maxCoins(self, nums: list[int]) -> int:
        N = len(nums)
        B = [1] + nums + [1]

        @cache
        def f (i, j):
            if i > j:
                return 0
            elif i == j:
                return B[i - 1] * B[i] * B[i + 1]

            maxCoins = 0
            for k in range(i, j + 1):
                maxCoins = max(maxCoins, f(i, k - 1) + (B[i - 1] * B[k] * B[j + 1]) + f(k + 1, j))
 
            return maxCoins

        return f(1, N)