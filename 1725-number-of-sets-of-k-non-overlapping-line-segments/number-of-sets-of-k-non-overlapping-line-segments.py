class Solution:
    def numberOfSets(self, n: int, k: int) -> int:
        self.MOD = 10 ** 9 + 7

        @cache
        def f (N, K, running):
            if N < K:
                return 0
            if K == 0:
                return 1

            segs = 0
            if running:
                segs = (segs + f(N - 1, K, True)) % self.MOD
                segs = (segs + f(N, K - 1, False)) % self.MOD
            else:
                segs = (segs + f(N - 1, K, False)) % self.MOD
                segs = (segs + f(N - 1, K, True)) % self.MOD
            
            return segs

        return f(n, k, False)