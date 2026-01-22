class Solution {
    public int findMiddleIndex(int[] nums) {
        int right = 0;
        for (int num: nums) right += num;
        int left = 0;

        for (int i = 0, n = nums.length; i < n; i++) {
            right -= nums[i];
            if (left == right) return i;
            left += nums[i];
        }
        
        return -1;
    }
}