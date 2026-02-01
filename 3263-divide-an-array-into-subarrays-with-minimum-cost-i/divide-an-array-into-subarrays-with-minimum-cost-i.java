class Solution {
    public int minimumCost(int[] nums) {
        int n = nums.length;

        int Min1 = 51, Min2 = 51;
        for (int i = 1; i < n; i++) {
            if (nums[i] <= Min1) {
                Min2 = Min1;
                Min1 = nums[i];
            } else if (nums[i] < Min2) {
                Min2 = nums[i];
            }
        }

        return Min1 + Min2 + nums[0];
    }
}