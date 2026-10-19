class Solution:
    def twoEggDrop(self, n: int) -> int:
        @cache
        def f(n, e):
            if n <= 1:
                return 1
            if e == 1:
                return n
            
            result = float('inf')
            for i in range(1, n + 1):
                result = min(result, max(f(n - i, e), f(i - 1, e - 1)) + 1)

            return result

        return f(n, 2)