class Solution:
    def firstStableIndex(self, nums: list[int], k: int) -> int:
        N = len(nums)

        RM = nums[:]
        for i in range(N - 2, -1, -1):
            RM[i] = min(RM[i], RM[i + 1])

        LM = 0
        for i in range(N):
            LM = max(LM, nums[i])
            if LM - RM[i] <= k:
                return i
        
        return -1
        