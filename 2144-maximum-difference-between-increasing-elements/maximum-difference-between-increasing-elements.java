class Solution {
    public int maximumDifference(int[] nums) {
        int maxDiff = 0, minVal = nums[0], n = nums.length;

        for (int i = 1; i < n; i++) {
            maxDiff = Math.max(maxDiff, nums[i] - minVal);
            minVal = Math.min(minVal, nums[i]);
        }

        return maxDiff == 0 ? -1 : maxDiff;
    }
}