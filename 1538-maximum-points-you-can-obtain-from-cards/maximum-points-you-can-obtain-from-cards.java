class Solution {
    public int maxScore(int[] cardPoints, int k) {
        final int N = cardPoints.length;

        int[] ps = new int[N + 1];
        for (int i = 0; i < N; i++) {
            ps[i + 1] = ps[i] + cardPoints[i];
        }

        int score = 0;
        for (int K = 0; K <= k; K++) {
            score = Math.max(score, ps[K] + (ps[N] - ps[N - (k - K)]));
        }

        return score;
    }
}