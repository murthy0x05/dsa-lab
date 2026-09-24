class Solution:
    def smallestIndex(self, nums: List[int]) -> int:
        N = len(nums)

        for i in range(N):
            if sum([int(c) for c in str(nums[i])]) == i:
                return i
            
        return -1