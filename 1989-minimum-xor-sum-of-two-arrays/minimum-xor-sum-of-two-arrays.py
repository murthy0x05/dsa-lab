from functools import cache

class Solution:
    def minimumXORSum(self, nums1: List[int], nums2: List[int]) -> int:
        self.N = len(nums1)

        @cache
        def f (i, j):
            if i == self.N:
                return 0

            result = float('inf')
            for k in range(self.N):
                if (j & (1 << k)) == 0:
                    result = min(result, (nums1[i] ^ nums2[k]) + f(i + 1, j | (1 << k)))
            
            return result

        return f(0, 0)