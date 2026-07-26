class Solution:
    def firstMissingPositive(self, nums: List[int]) -> int:
        N = len(nums)

        for i in range(N):
            while 1 <= nums[i] <= N and (i + 1) != nums[i]:
                next = nums[i] - 1
                if nums[next] == (next + 1):
                    break
                nums[i], nums[next] = nums[next], nums[i]
        
        for i in range(N):
            if nums[i] != i + 1:
                return i + 1
        
        return N + 1