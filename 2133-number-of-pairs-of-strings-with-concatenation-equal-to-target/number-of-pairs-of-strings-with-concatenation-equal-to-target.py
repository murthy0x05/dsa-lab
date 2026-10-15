class Solution:
    def numOfPairs(self, nums: list[str], target: str) -> int:
        N = len(nums)

        result = 0
        for i in range(N):
            for j in range(i + 1, N):
                if nums[i] + nums[j] == target:
                    result += 1
                if nums[j] + nums[i] == target:
                    result += 1

        return result