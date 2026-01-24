class Solution {
    private static int[] counts;
    public Solution() {
        counts = new int[100001];
    }
    public int minPairSum(int[] nums) {
        int n = nums.length;

        int l = Integer.MAX_VALUE,
            r = Integer.MIN_VALUE;
        for (int i = 0; i < n; i++) {
            counts[nums[i]]++;
            l = Math.min(l, nums[i]);
            r = Math.max(r, nums[i]);
        }

        for (int i = 1; i < 6; i++) {
            for (int j = 0; j < counts[i]; j++) {
                System.out.print(i + " ");
            }
        }

        int result = l + l;
        while (l <= r) {
            if (0 == counts[l]) l++;
            else if (0 == counts[r]) r--;
            else {
                result = Math.max(result, l + r);
                counts[l]--; counts[r]--;
            }
        }

        return result;
    }
}