class Solution {
    public int findLHS(int[] nums) {
        int n = nums.length;
        int currCount = 0, nextCount = 0;
        Arrays.sort(nums);

        int start = 0, end = 0, longest = 0;
        while (end < n) {
            while (end < n && nums[end] - nums[start] < 2) {
                end++;
            }
            if (nums[end - 1] - nums[start] == 1) {
                longest = Math.max(longest, end - start);
            }
            start++;
        }

        return longest;
    }
}