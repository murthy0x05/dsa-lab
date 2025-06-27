class Solution {
    public boolean canJump(int[] nums) {
        int n = nums.length;
        int maxReachability = 0;
        int i = 0;
        while (i < n) {
            maxReachability = Math.max(maxReachability, i + nums[i]);
            if (i < maxReachability) {
                i += 1;
            } else {
                break;
            }
        }

        return i >= n-1;
    }
}