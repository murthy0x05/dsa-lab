class Solution {
    public long minimumCost(String source, String target, char[] original, char[] changed, int[] cost) {
        final long INF = (int)2e9 + 1;

        long[][] minCost = new long[26][26];
        for (int i = 0; i < 26; i++)
            Arrays.fill(minCost[i], INF);
        
        for (int i = 0, len = original.length; i < len; i++) {
            int id1 = original[i] - 'a',
                id2 = changed[i] - 'a';
            minCost[id1][id2] = Math.min(minCost[id1][id2], (long)cost[i]);
        }
        for (int k = 0; k < 26; k++) 
            for (int i = 0; i < 26; i++) 
                for (int j = 0; j < 26; j++) 
                    minCost[i][j] = Math.min(minCost[i][j], minCost[i][k] + minCost[k][j]);
        
        long total = 0L;
        for (int i = 0, len = source.length(); i < len; i++) {
            int id1 = source.charAt(i) - 'a',
                id2 = target.charAt(i) - 'a';
            if (id1 != id2) {
                if (minCost[id1][id2] == INF)
                    return -1;
                total += minCost[id1][id2];
            }
        }

        return total;
    }
}