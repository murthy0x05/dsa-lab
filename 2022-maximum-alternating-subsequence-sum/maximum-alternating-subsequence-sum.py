class Solution:
    def maxAlternatingSum(self, nums: List[int]) -> int:
        N = len(nums)

        @cache
        def f (i, even):
            if i == N:
                return 0

            if even:
                return max(nums[i] + f(i + 1, False), f(i + 1, True))
            else:
                return max(-nums[i] + f(i + 1, True), f(i + 1, False))

        return f(0, True)
            