class Solution:
    def goodIndices(self, nums: List[int], k: int) -> List[int]:
        N = len(nums)

        psl, psr = [0] * (N + 1), [0] * (N + 1)
        
        psl[1] = 1
        for i in range(1, N):
            if nums[i] <= nums[i - 1]:
                psl[i + 1] = psl[i] + 1
            else:
                psl[i + 1] = 1
        
        psr[N - 1] = 1
        for i in range(N - 2, -1, -1):
            if nums[i] <= nums[i + 1]:
                psr[i] = psr[i + 1] + 1
            else:
                psr[i] = 1
        
        result = []
        for i in range(k, N - k):
            if psl[i] >= k and psr[i + 1] >= k:
                result.append(i)

        return result 
