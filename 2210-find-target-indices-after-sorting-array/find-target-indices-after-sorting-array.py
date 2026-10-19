class Solution:
    def targetIndices(self, nums: list[int], target: int) -> list[int]:
        return [i for i, val in enumerate(sorted(nums)) if val == target]