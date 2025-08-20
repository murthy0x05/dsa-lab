class Solution {
    public int findPoisonedDuration(int[] timeSeries, int duration) {
        int n = timeSeries.length;

        int result = 0;
        int start = -1, end = -1;
        for (int i = 0; i < n; i++) {
            start = Math.max(end, timeSeries[i]);
            end = timeSeries[i] + duration;

            result += end - start;
        }

        return result;        
    }
}