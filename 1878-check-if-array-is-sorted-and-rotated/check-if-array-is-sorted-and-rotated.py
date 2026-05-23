class Solution:
    def check(self, nums: List[int]) -> bool:
        return sum([0 if nums[(i - 1) % len(nums)] <= nums[i] else 1 for i in range(0, len(nums))]) <= 1 