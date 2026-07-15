class Solution:
    def maxOperations(self, nums: List[int], k: int) -> int:
        N = len(nums)
        nums.sort()

        ops = 0
        l, r = 0, N - 1
        while l < r:
            if nums[l] + nums[r] == k:
                ops += 1
                l += 1
                r -= 1
            elif nums[l] + nums[r] < k:
                l += 1
            else:
                r -= 1
        
        return ops