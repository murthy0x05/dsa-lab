class Solution {
    public int largestPerimeter(int[] nums) {
        int n = nums.length;
        Arrays.sort(nums);

        int result = 0;
        for (int i = n - 1; i >= 2; i--) {
            if (nums[i - 1] + nums[i - 2] > nums[i]) {
                result = Math.max(result, nums[i] + nums[i-1] + nums[i-2]);
            }
        }

        return result;
    }
}