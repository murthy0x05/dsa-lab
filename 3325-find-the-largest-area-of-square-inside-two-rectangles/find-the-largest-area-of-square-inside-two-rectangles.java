class Solution {
    private long sidelen(int a1, int b1, int a2, int b2, int c1, int d1, int c2, int d2) {
        int x1 = Math.max(a1, c1);
        int y1 = Math.max(b1, d1);
        int x2 = Math.min(a2, c2);
        int y2 = Math.min(b2, d2);

        if (x1 >= x2 || y1 >= y2) return 0;
        return Math.min(x2 - x1, y2 - y1);
    }
    public long largestSquareArea(int[][] bottomLeft, int[][] topRight) {
        int n = bottomLeft.length;

        long side = 0;
        for (int i = 0; i < n; i++) {
            int a1 = bottomLeft[i][0], b1 = bottomLeft[i][1];
            int a2 = topRight[i][0], b2 = topRight[i][1];
            for (int j = i + 1; j < n; j++) {
                int c1 = bottomLeft[j][0], d1 = bottomLeft[j][1];
                int c2 = topRight[j][0], d2 = topRight[j][1];

                side = Math.max(side, sidelen(a1, b1, a2, b2, c1, d1, c2, d2));
            }
        }

        return side * side;
    }
}