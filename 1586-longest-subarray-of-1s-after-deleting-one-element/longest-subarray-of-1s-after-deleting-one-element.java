class Solution {
    public int longestSubarray(int[] nums) {
        int n = nums.length;

        int start = 0, end = 0;
        int zeroes = 0, maxlen = 0;
        while (end < n) {
            if (nums[end] == 0) zeroes++;
            while (zeroes > 1) {
                if (nums[start] == 0) zeroes--;
                start++;
            }
            maxlen = Math.max(maxlen, end - start);
            end++;
        }

        return maxlen;
    }
}