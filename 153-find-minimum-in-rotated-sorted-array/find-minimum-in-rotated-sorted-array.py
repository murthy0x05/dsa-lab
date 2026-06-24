class Solution:
    def findMin(self, nums: List[int]) -> int:
        N = len(nums)

        l, r = 0, N - 1
        while l <= r:
            if nums[l] <= nums[r]:
                return nums[l]

            m = l + ((r - l) >> 1)
            n, p = nums[(m + 1) % N], nums[(m - 1 + N) % N]
            if nums[m] < n and nums[m] < p:
                return nums[m]
            elif nums[l] <= nums[m]:
                l = m + 1
            else:
                r = m - 1
        
        return nums[l]