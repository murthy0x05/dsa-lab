class Solution {
    public int maxFreeTime(int eventTime, int k, int[] startTime, int[] endTime) {
        int n = startTime.length;

        int[] gaps = new int[n + 1];
        gaps[0] = startTime[0];
        gaps[n] = eventTime - endTime[n - 1];
        for (int i = 0; i < n - 1; i++) {
            gaps[i + 1] = startTime[i + 1] - endTime[i];
        }

        int window = 0, result = 0;
        for (int i = 0; i < k; i++) {
            window += gaps[i];
        }
        for (int i = k; i <= n; i++) {
            window += gaps[i];
            result = Math.max(result, window);
            window -= gaps[i - k];
        }

        return result;



    }
}