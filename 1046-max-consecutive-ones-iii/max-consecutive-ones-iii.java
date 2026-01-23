class Solution {
    public int longestOnes(int[] nums, int k) {
        int n = nums.length;

        int len = 0;
        for (int l = 0, r = 0, z = 0; r < n; r++) {
            z += nums[r] == 0 ?1:0;
            if (z > k) {
                z -= nums[l] == 0 ?1:0;
                l++;
            }

            len = Math.max(len, r - l + 1);
        }

        return len;
    }
}