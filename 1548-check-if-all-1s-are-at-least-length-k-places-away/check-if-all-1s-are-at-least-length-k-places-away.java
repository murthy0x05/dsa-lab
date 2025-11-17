class Solution {
    public boolean kLengthApart(int[] nums, int k) {
        int n = nums.length;

        for (int i = 0, prev = -10000; i < n; i++) {
            if (nums[i] == 1) {
                if (i - prev - 1 < k) {
                    return false;
                }
                prev = i;
            }
        }

        return true;
    }
}