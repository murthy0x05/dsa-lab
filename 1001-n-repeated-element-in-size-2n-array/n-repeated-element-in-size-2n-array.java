class Solution {
    public int repeatedNTimes(int[] nums) {
        int candidate = nums[0], votes = 1;
        for (int i = 1, n = nums.length; i < n; i++) {
            if (nums[i] == nums[i - 1]) {
                return nums[i];
            } else if (nums[i] == candidate) {
                return candidate;
            }
        }

        return nums[nums.length - 1];
    }
}