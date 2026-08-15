class Solution:
    def longestSubsequence(self, nums: List[int]) -> int:
        if nums.count(0) == len(nums):
            return 0
        
        if reduce(operator.xor, nums, 0) == 0:
            return len(nums) - 1
        else:
            return len(nums)