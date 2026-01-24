class Solution:
    def singleNonDuplicate(self, nums: List[int]) -> int:
        low, high = 0, len(nums) - 1
        while (low <= high):
            mid = low + ((high - low) >> 1)
            if mid == low or mid == high or ((nums[mid] != nums[mid - 1]) and (nums[mid] != nums[mid + 1])):
                return nums[mid]
            elif ((high - mid) & 1):
                if nums[mid] == nums[mid + 1]: 
                    high = mid - 1
                else:
                    low = mid + 1
            else:
                if nums[mid] == nums[mid + 1]:
                    low = mid + 2
                else:
                    high = mid - 2

        return -1