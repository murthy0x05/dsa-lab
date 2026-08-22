class Solution:
    def validPartition(self, nums: List[int]) -> bool:
        N = len(nums)

        dp = [False] * (N + 1)
        dp[0] = True
        for i in range(1, N):
            if nums[i] == nums[i - 1]:
                dp[i + 1] = dp[i - 1] or (dp[i] and i - 2 >= 0 and nums[i - 1] == nums[i - 2])
            elif nums[i] - nums[i - 1] == 1:
                dp[i + 1] = i - 2 >= 0 and dp[i - 2] and nums[i - 1] - 1 == nums[i - 2]

        return dp[-1]