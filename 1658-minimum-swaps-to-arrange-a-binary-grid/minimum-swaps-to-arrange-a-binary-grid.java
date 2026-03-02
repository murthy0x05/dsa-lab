class Solution {
    public int minSwaps(int[][] grid) {
        final int N = grid.length;

        int[] zeroes = new int[N];
        for (int i = 0; i < N; i++) {
            int trailingZeroes = 0;
            for (int j = N - 1; j >= 0 && grid[i][j] == 0; j--) {
                trailingZeroes++;
            }
            zeroes[i] = trailingZeroes; 
        }

        int swaps = 0;
        for (int i = 0; i < N; i++) {
            int needed = N - i - 1,
                j = i;
            while (j < N && zeroes[j] < needed) j++;
            
            if (j == N) return -1;
            while (j > i) {
                zeroes[j] = zeroes[j - 1] ^ zeroes[j] ^ (zeroes[j - 1] = zeroes[j]);
                swaps++;
                j--;
            }
        }

        return swaps;
    }
}