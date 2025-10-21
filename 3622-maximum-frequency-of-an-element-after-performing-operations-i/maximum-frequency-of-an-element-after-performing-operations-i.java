class Solution {
    public int maxFrequency(int[] nums, int k, int numOperations) {
        int n = nums.length;

        int[] ps = new int[(int)1e5 + 1];
        for (int i = 0; i < n; i++) {
            ps[nums[i]]++;
        }
        for (int i = 1; i < (int)1e5 + 1; i++) {
            ps[i] += ps[i - 1];
        }

        int result = 0;
        for (int i = 1; i < (int)1e5 + 1; i++) {
            int s = Math.max(0, i - k - 1),
                e = Math.min((int)1e5, i + k);
            int f = ps[i] - ps[i - 1];
            result = Math.max(result, Math.min(numOperations, ps[e] - ps[s] - f) + f);
        }

        return result;
    }
}