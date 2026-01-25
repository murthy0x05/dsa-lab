class Solution {
    public int threeSumClosest(int[] nums, int target) {
        Arrays.sort(nums);

        int closest = -1, abs_sum = 13001;
        for (int i = 0, len = nums.length - 2; i < len; i++) {
            int l = i + 1, r = len + 1;
            while (l < r) {
                int sum = nums[i] + nums[l] + nums[r];
                if (Math.abs(sum - target) < abs_sum) {
                    abs_sum = Math.abs(sum - target);
                    closest = sum;
                } 
                if (sum - target < 0) {
                    l++;
                } else {
                    r--;
                }
            }
        }

        return closest;
    }
}