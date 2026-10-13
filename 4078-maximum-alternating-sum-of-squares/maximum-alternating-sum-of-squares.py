class Solution:
    def maxAlternatingSum(self, nums: List[int]) -> int:
        N = len(nums)

        sqs = sorted([num * num for num in nums], reverse = True)
        return sum([(-1 if i >= ((N + 1) // 2) else 1) * sqs[i] for i in range(N)])