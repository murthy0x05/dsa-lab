class Solution:
    def kLengthApart(self, nums: List[int], k: int) -> bool:
        n = len(nums)
        
        prev = -100000
        for i in range(n):
            if 1 == nums[i]:
                if i - prev - 1 < k:
                    return False
                else:
                    prev = i

        return True
