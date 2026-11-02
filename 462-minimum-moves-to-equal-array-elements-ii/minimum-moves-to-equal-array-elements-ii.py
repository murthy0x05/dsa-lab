class Solution:
    def minMoves2(self, nums: List[int]) -> int:
        N = len(nums)
        if N == 1:
            return 0

        def qs(K):
            L, R = 0, N
            while L < R:
                P = nums[random.randrange(L, R)]
                lt, gt = L, R

                i = L
                while i < gt:
                    if nums[i] < P:
                        nums[lt], nums[i] = nums[i], nums[lt]
                        lt += 1
                        i += 1
                    elif nums[i] > P:
                        gt -= 1
                        nums[gt], nums[i] = nums[i], nums[gt]
                    else:
                        i += 1
                
                if K < lt:
                    R = lt
                elif K >= gt:
                    L = gt
                else:
                    return nums[K]

            return -1

        res = 0
        mid = qs(N >> 1)
        for i in nums:
            res += abs(i - mid)

        return res