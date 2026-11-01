class Solution:
    def minOperations(self, nums1: List[int], nums2: List[int]) -> int:
        N = len(nums1)

        result = 0
        for i in range(N):
            result += abs(nums1[i] - nums2[i])

        best = float('inf')
        for i in range(N):
            if nums1[i] < nums2[i]:
                if nums1[i] <= nums2[-1] <= nums2[i]:
                    best = 0
                    break
                else:
                    best = min(best, abs(nums1[i] - nums2[-1]), abs(nums2[i] - nums2[-1]))
            else:
                if nums1[i] >= nums2[-1] >= nums2[i]:
                    best = 0
                    break
                else:
                    best = min(best, abs(nums1[i] - nums2[-1]), abs(nums2[i] - nums2[-1]))

        return result + best + 1