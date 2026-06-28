class Solution {
    public int maximumElementAfterDecrementingAndRearranging(int[] arr) {
        final int N = arr.length;

        int curr = 1;
        Arrays.sort(arr);
        for (int i = 1; i < N; i++) {
            if (curr < arr[i]) {
                curr++;
            }
        }

        return curr;
    }
}