class Solution {
    private int binarySearch(int[] nums, int low, int high, int target) {
        while (low <= high) {
            int mid = (low + high) >> 1;
            if (nums[mid] == target) {
                return mid;
            } else if (nums[mid] < target) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }

        return -1;
    }
    private int findPivot(int[] nums) {
        int low = 0, high = nums.length - 1;

        while (low <= high) {
            if (nums[low] <= nums[high]) {
                return low;
            }
            int mid = (low + high) >> 1;
            if (nums[mid] > nums[high]) {
                low = mid + 1;
            } else {
                high = mid;
            }
        }

        return low;
    }
    public int search(int[] nums, int target) {
        int n = nums.length;
        int pivot = findPivot(nums); 
        if (pivot == 0) {
            return binarySearch(nums, 0, n-1, target);
        }
        if (nums[0] <= target) {
            return binarySearch(nums, 0, pivot - 1, target);
        } else {
            return binarySearch(nums, pivot, n - 1, target);
        }
    }
}