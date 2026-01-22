class Solution {
    public int[] runningSum(int[] nums) {
        for (int i = 1, n = nums.length; i < n; i++) {
            nums[i] += nums[i - 1];
        }

        return nums;
    }
}