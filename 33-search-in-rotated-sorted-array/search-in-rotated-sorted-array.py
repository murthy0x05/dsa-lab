class Solution:
    def search(self, nums: List[int], target: int) -> int:
        N = len(nums)

        low, high = 0, N - 1
        while low <= high:
            mid = low + ((high - low) >> 1)
            if nums[mid] == target:
                return mid
            elif nums[low] <= nums[mid]:
                if target >= nums[low] and target <= nums[mid]:
                    high = mid - 1
                else:
                    low = mid + 1
            else:
                if target >= nums[mid] and target <= nums[high]:
                    low = mid + 1
                else:
                    high = mid - 1
        
        return -1
