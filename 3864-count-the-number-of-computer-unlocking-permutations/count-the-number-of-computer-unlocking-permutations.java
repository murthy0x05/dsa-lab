class Solution {
    private final int MOD = (int)1e9 + 7;
    public int countPermutations(int[] complexity) {
        int n = complexity.length;

        for (int i = 1; i < n; i++) {
            if (complexity[i] <= complexity[0]) {
                return 0;
            }
        }

        long perms = 1;
        for (int i = 2; i <= n - 1; i++) {
            perms = (perms * 1L * i) % MOD;
        }

        return (int)perms;
    }
}