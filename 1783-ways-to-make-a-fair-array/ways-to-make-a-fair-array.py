class Solution:
    def waysToMakeFair(self, nums: list[int]) -> int:
        N = len(nums)

        ops, eps = [0 for _ in range(N + 1)], [0 for _ in range(N + 1)]
        for i in range(N):
            ops[i + 1] += ops[i]
            eps[i + 1] += eps[i]
            if i & 1:
                ops[i + 1] += nums[i]
            else:
                eps[i + 1] += nums[i]

        result = 0
        for i in range(N):
            if ops[i] + eps[N] - eps[i + 1] == eps[i] + ops[N] - ops[i + 1]:
                result += 1
        
        return result