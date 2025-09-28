class Solution {
    public int largestPerimeter(int[] nums) {
        int n = nums.length;
        nums = Arrays.stream(nums)
                     .boxed()
                     .sorted((a, b) -> b - a)
                     .mapToInt(Integer::intValue)
                     .toArray();

        int result = 0;
        for (int i = 0; i < n - 2; i++) {
            if (nums[i + 2] + nums[i + 1] > nums[i]) {
                result = Math.max(result, nums[i] + nums[i+1] + nums[i+2]);
            }
        }

        return result;
    }
}