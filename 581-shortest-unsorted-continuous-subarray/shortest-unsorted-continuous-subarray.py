class Solution:
    def findUnsortedSubarray(self, nums: List[int]) -> int:
        N = len(nums)

        Min, Max = float('inf'), float('-inf')
        for i in range(1, N):
            if Min != float('inf') or nums[i - 1] > nums[i]:
                Min = min(Min, nums[i])
        
        for i in range(N - 2, -1, -1):
            if Max != float('-inf') or nums[i] > nums[i + 1]:
                Max = max(Max, nums[i])
        
        l, r = 0, N - 1
        while l < N:
            if nums[l] > Min:
                break
            l += 1
        while r >= 0:
            if nums[r] < Max:
                break
            r -= 1
    
        return max(0, r - l + 1)