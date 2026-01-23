class Solution {
    public int minSubArrayLen(int target, int[] nums) {
        final int n = nums.length;

        Function<Integer, Boolean> feasible = (Integer K) -> {
            int sum = 0;
            for (int l = 0, r = 0; r < n; r++) {
                sum += nums[r];
                if (r - l + 1 == K) {
                    if (sum >= target) {
                        return true;
                    }
                    sum -= nums[l];
                    l++;
                }
            }

            return false;
        };

        int len = 0;
        int low = 1, high = n;
        while (low <= high) {
            int mid = low + ((high - low) >> 1);
            if (feasible.apply(mid)) {
                len = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        return len;
    }
}