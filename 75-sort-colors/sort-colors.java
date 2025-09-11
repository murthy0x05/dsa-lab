class Solution {
    public void sortColors(int[] nums) {
        int n = nums.length;

        int low = -1, mid = 0, high = n;
        while (mid < high) {
            if (nums[mid] == 0) {
                low++;
                nums[mid] = nums[low] ^ nums[mid] ^ (nums[low] = nums[mid]);
                mid++;
            } else if (nums[mid] == 1) {
                mid++;
            } else {
                high--;
                nums[mid] = nums[high] ^ nums[mid] ^ (nums[high] = nums[mid]);
            }
        }
    }
}