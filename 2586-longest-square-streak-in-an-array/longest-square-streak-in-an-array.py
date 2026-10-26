class Solution:
    def longestSquareStreak(self, nums: list[int]) -> int:
        N = len(nums)

        nums.sort()

        @cache
        def f(prev):
            next = prev * prev

            l, r = 0, N - 1
            while l <= r:
                mid = l + ((r - l) >> 1)
                if nums[mid] < next:
                    l = mid + 1
                else:
                    r = mid - 1
            
            if l < N and nums[l] == next:
                return 1 + f(next)
            else:
                return 1

        result = 1
        for i in range(N):
            result = max(result, f(nums[i]))

        return result if result > 1 else -1