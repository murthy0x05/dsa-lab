class Solution {
    public int findFinalValue(int[] nums, int original) {
        int n = nums.length;

        Arrays.sort(nums);
        for (int i = 0; i < n; i++) {
            if (original == nums[i]) {
                original *= 2;
            }
        }

        return original;
    }
}