class Solution {
    private boolean canAssign(int[] nums, int capability, int k) {
        for (int i = 0, n = nums.length; i < n; i++) {
            if (nums[i] <= capability) {
                k--; i++;
            }
        }

        return k <= 0;
    }
    public int minCapability(int[] nums, int k) {
        int n = nums.length;
        int minVal = Integer.MAX_VALUE;
        int maxVal = Integer.MIN_VALUE;
        for (int i = 0; i < n; i++) {
            minVal = Math.min(minVal, nums[i]);
            maxVal = Math.max(maxVal, nums[i]);
        }

        int low = minVal, high = maxVal, result = 0;
        while (low <= high) {
            int mid = low + ((high - low) >> 1);
            if (canAssign(nums, mid, k)) {
                result = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        return result;
    }
}