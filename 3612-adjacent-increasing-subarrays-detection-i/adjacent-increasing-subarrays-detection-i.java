class Solution {
    public boolean hasIncreasingSubarrays(List<Integer> nums, int k) {
        int n = nums.size();

        int[] inc = new int[n]; inc[n - 1] = 1;
        for (int i = n - 2; i >= 0; i--) {
            if (nums.get(i) < nums.get(i + 1)) {
                inc[i] = inc[i + 1] + 1;
            } else {
                inc[i] = 1;
            }
        }

        for (int i = 0; i < n - 2 * k + 1; i++) {
            if (inc[i] >= k && inc[i + k] >= k) {
                return true;
            }
        }

        return false;   
    }
}