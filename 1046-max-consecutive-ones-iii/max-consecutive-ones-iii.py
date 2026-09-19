class Solution:
    def longestOnes(self, nums: list[int], k: int) -> int:
        N = len(nums)

        largest = 0
        l, z = 0, 0
        for r in range(N):
            z += 1 if nums[r] == 0 else 0
            if z > k:
                z -= 1 if nums[l] == 0 else 0
                l += 1
            else:
                largest = max(largest, r - l + 1)

        return largest