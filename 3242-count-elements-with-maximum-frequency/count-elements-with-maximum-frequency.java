class Solution {
    public int maxFrequencyElements(int[] nums) {
        int n = nums.length;
        int counts[] = new int[101];

        int maxi = 0, result = 0;
        for (final int num: nums) {
            counts[num]++;
            if (maxi == counts[num]) {
                result += maxi;
            } else if (counts[num] > maxi) {
                maxi = counts[num];
                result = maxi;
            }
        }

        return result;
    }
}