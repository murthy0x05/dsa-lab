class Solution {
    public int[] minBitwiseArray(List<Integer> nums) {
        int n = nums.size();

        int[] arr = new int[n];
        for (int i = 0; i < n; i++) {
            if ((nums.get(i) & 1) == 1) {
                arr[i] = (~((~nums.get(i) & -(~nums.get(i))) >> 1)) & nums.get(i);
            } else {
                arr[i] = -1;
            }
        }

        return arr;
    }
}