class Solution {
    public int pivotIndex(int[] nums) {
        int right = Arrays.stream(nums)
                          .sum();
        int left = 0;

        for (int i = 0, n = nums.length; i < n; i++) {
            right -= nums[i];
            if (left == right) {
                return i;
            } else {
                left += nums[i];
            }
        }
        
        return -1;
    }
}