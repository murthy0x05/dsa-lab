class Solution:
    def minOperations(self, nums: list[int], x: int) -> int:
        N = len(nums)
        
        ps = [0] * (N + 1)
        for i in range(N):
            ps[i + 1] = ps[i] + nums[i]

        rs = 0
        l, r = 0, N - 1
        smallest = float('inf')
        while l <= r:
            m = l + ((r - l) >> 1)
            if ps[m] < (x - rs):
                l = m + 1
            else:
                r = m - 1
        
        if ps[l] == (x - rs):
            smallest = min(smallest, l)

        for i in range(N - 1, -1, -1):
            rs += nums[i]

            l, r = 0, i - 1
            while l <= r:
                m = l + ((r - l) >> 1)
                if ps[m] < (x - rs):
                    l = m + 1
                else:
                    r = m - 1
            
            if ps[l] == (x - rs):
                smallest = min(smallest, N - i + l)
            
        if smallest != float('inf'):
            return smallest

        return -1