class Solution {
    public int minSubArrayLen(int target, int[] nums) {
        int n = nums.length;

        int start = 0, end = 0;
        int len = n + 1;
        int sum = 0;
        while (start < n) {
            while (end < n && sum < target) {
                sum += nums[end];
                end++;
            }

            if (sum >= target) {
                len = Math.min(len, end - start);
            }

            sum -= nums[start];
            start++;
        }

        return (len == n + 1) ? 0 : len;
    }
}