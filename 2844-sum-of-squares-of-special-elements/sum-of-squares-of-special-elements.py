class Solution:
    def sumOfSquares(self, nums: List[int]) -> int:
        N = len(nums)

        result = 0
        for i in range(1, N + 1):
            if N % i == 0:
                result += nums[i - 1] * nums[i - 1]

        return result