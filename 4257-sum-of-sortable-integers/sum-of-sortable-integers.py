class Solution:
    def sortableIntegers(self, nums: list[int]) -> int:
        N = len(nums)

        def f(k):
            prev = 0
            for i in range(0, N, k):
                dec = 0

                mn, mx = float('inf'), float('-inf')
                for j in range(k):
                    if nums[i + j] > nums[i + (j + 1) % k]:
                        dec += 1

                    mn = min(mn, nums[i + j])
                    mx = max(mx, nums[i + j])
                
                if dec > 1 or prev > mn:
                    return False
                
                prev = mx

            return True

        k = 1
        result = 0
        while k * k <= N:
            if N % k == 0:
                result += k if f(k) else 0 
                result += N // k if ((N // k) != k and f(N // k)) else 0

            k += 1

        return result