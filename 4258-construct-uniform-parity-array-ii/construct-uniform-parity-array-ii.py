class Solution:
    def uniformArray(self, nums1: list[int]) -> bool:
        N = len(nums1)

        if any([(nums1[i - 1] & 1) ^ (nums1[i] & 1) for i in range(1, N)]):
            return (min(nums1) & 1) == 1
        else:
            return True