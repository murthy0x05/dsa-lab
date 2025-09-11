class Solution:
    def sortColors(self, nums: List[int]) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        low, mid, high = -1, 0, len(nums)

        while (mid < high):
            if 0 == nums[mid]:
                low += 1
                nums[low], nums[mid] = nums[mid], nums[low]
                mid += 1
            elif 1 == nums[mid]:
                mid += 1
            else:
                high -= 1
                nums[mid], nums[high] = nums[high], nums[mid]
                
