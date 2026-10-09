class Solution:
    def maxScoreIndices(self, nums: list[int]) -> list[int]:
        N = len(nums)

        pc = [0 for _ in range(N + 1)]
        for i in range(N):
            pc[i + 1] = pc[i] + 1 - nums[i]

        result = []
        maxScore = 0
        for i in range(N + 1):
            score = pc[i] + ((N - i) - (pc[N] - pc[i]))
            if score > maxScore:
                result = [i]
                maxScore = score
            elif score == maxScore:
                result.append(i)

        return result