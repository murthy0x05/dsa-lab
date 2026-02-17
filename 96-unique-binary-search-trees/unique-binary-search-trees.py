import functools

class Solution:
    def numTrees(self, n: int) -> int:
        @functools.cache
        def f(low, high):
            if low >= high:
                return 1

            ways = 0
            for i in range(low, high + 1):
                ways += f(low, i - 1) * f(i + 1, high)
            
            return ways

        return f(1, n)