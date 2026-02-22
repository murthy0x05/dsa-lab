class Solution {
    public int numDistinct(String s, String t) {
        final int N = s.length(),
                  M = t.length();
        if (N < M) {
            return 0;
        }

        long[] prev = new long[M + 1]; prev[0] = 1;
        for (int i = 0; i < N; i++) {
            long[] curr = new long[M + 1]; curr[0] = 1;
            for (int j = 0; j < M; j++) {
                curr[j + 1] = prev[j + 1];
                if (s.charAt(i) == t.charAt(j)) {
                    curr[j + 1] += prev[j];
                }
            }
            prev = curr;
        }

        return (int)prev[M];
    }
}