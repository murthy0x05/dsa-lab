class Solution {
    public int findSmallestInteger(int[] nums, int value) {
        int n = nums.length;

        int[] counts = new int[value + 1];
        for (int i = 0; i < n; i++) {
            counts[((nums[i] % value) + value) % value]++;
        }

        for (int i = 0; i < n; i++) {
            if (counts[i % value] == 0) return i;
            else {
                counts[i % value]--;
            } 
        }


        return n;
    }
}