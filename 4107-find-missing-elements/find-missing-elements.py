class Solution:
    def findMissingElements(self, nums: List[int]) -> List[int]:
        vals = set(nums)

        result = []
        for val in range(min(nums) + 1, max(nums)):
            if val not in vals:
                result.append(val)

        return result
