class Solution:
    def minOperations(self, nums: list[int]) -> int:
        N = len(nums)

        O, T = 0, 0
        for num in nums:
            t = 0
            val = num
            while val > 0:
                if val & 1:
                    val -= 1
                    O += 1
                else:
                    val = val >> 1
                    t += 1
            
            T = max(T, t)

        return O + T