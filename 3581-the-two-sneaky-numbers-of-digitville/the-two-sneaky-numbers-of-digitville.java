class Solution {
    public int[] getSneakyNumbers(int[] nums) {
        int n = nums.length;
        Set<Integer> seen = new HashSet<>();

        int[] ans = new int[2]; int idx = 0;
        for (int i = 0; i < n; i++) {
            if (!seen.add(nums[i])) {
                ans[idx++] = nums[i];
            }
        }

        return ans;
    }
}