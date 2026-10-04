from functools import cache

class Solution:
    def countHousePlacements(self, n: int) -> int:
        MOD = 10 ** 9 + 7

        @cache
        def f (i, H):
            if i == 0:
                return 1
            
            if H == 0:
                return (f(i - 1, 0) + f(i - 1, 1) + f(i - 1, 2) + f(i - 1, 3)) % MOD
            elif H == 1:
                return (f(i - 1, 0) + f(i - 1, 2)) % MOD
            elif H == 2:
                return (f(i - 1, 0) + f(i - 1, 1)) % MOD
            else:
                return f(i - 1, 0) % MOD

        return f(n, 0)
