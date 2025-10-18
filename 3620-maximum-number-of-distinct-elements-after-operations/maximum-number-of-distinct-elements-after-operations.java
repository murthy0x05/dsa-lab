class Solution {
    public int maxDistinctElements(int[] nums, int k) {
        int n = nums.length;
        
        Arrays.sort(nums);
        nums[0] -= k; int dists = 1, greatest = nums[0];
        for (int i = 1; i < n; i++) {
            int maxi = Math.max(nums[i] - k, greatest + 1);
            if (maxi <= nums[i] + k) {
                nums[i] = greatest = maxi;
                dists++;
            }
        }
        
        return dists;
    }
}