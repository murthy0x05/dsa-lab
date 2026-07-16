import math

class Solution:
    def gcdSum(self, nums: list[int]) -> int:
        # def gcd(a, b):
        #     return a if b == 0 else gcd(b, a % b)
        
        N = len(nums)

        mx = 0
        pg = [0 for _  in range(N)]
        for i in range(N):
            mx = max(mx, nums[i])
            pg[i] = gcd(nums[i], mx)
        pg.sort()

        total = 0
        l, r = 0, N - 1
        while l < r:
            total += gcd(pg[l], pg[r])
            l += 1
            r -= 1
        
        return total
