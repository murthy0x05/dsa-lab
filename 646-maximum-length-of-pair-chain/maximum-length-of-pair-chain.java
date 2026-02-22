class Solution {
    public int findLongestChain(int[][] pairs) {
        final int N = pairs.length;

        Arrays.sort(pairs, (int[] a, int[] b) -> {
            if (a[1] != b[1])
                return Integer.compare(a[1], b[1]);
            else
                return Integer.compare(a[0], b[0]);
        });

        int longest = 0;
        for (int i = 0, prev = -1001; i < N; i++) {
            if (prev < pairs[i][0]) {
                prev = pairs[i][1];
                longest++;
            }
        }

        return longest;
    }
}