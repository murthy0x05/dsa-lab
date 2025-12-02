class Solution {
    private final int MOD = (int)1e9 + 7;
    public int countTrapezoids(int[][] points) {
        Arrays.sort(points, (a, b) -> {
            if (a[1] != b[1]) {
                return Integer.compare(a[1], b[1]);
            } else {
                return Integer.compare(a[0], b[0]);
            }
        });

        int n = points.length;
        int sum = 0,
            result = 0;
        for (int i = 1, s; i < n; i++) {
            s = 1;
            while (i < n && points[i][1] == points[i - 1][1]) {
                i++;
                s++;
            }

            if (s >= 2) {
                int sC2 = (int)(((s * 1L * (s - 1)) / 2) % MOD);
                result = (int)((result + (sum * 1L * sC2)) % MOD);
                sum = (int)((sum + sC2) % MOD);
            }
        }

        return result;
    }
}