class Solution {
    private final int MOD = (int)1e9 + 7;
    private int[] preComputeTwoPower(int n) {
        int[] twoPower = new int[n];
        twoPower[0] = 1;
        for (int i = 1; i < n; i++) {
            twoPower[i] = (int)((twoPower[i - 1] * 2L) % MOD);
        }
        return twoPower;
    }
    public int numSubseq(int[] nums, int target) {
        int n = nums.length, result = 0;
        Arrays.sort(nums);

        int[] twoPower = preComputeTwoPower(n);
        int start = 0, end = n - 1;
        while (start <= end) {
            if (nums[start] + nums[end] > target) {
                end -= 1;
            } else {
                result = (int)((result + twoPower[end - start]) % MOD);
                start += 1;
            }
        }

        return result;
        
    }
}