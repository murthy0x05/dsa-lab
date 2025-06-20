class Solution {
    private int computeMax(int[] news, int k) {
        int maxV = Math.max(news[0], news[3]);
        int minV = Math.min(news[0], news[3]);
        int maxH = Math.max(news[1], news[2]);
        int minH = Math.min(news[1], news[2]);
        
        maxV += Math.min(minV, k); k -= minV;
        if (k < 0) {
            maxV += k;
            k = 0;
        }
        maxH += Math.min(minH, k); k -= minH;
        if (k < 0) {
            maxH += k;
            k = 0;
        }

        return Math.abs(maxV) + Math.abs(maxH);
    }
    public int maxDistance(String s, int k) {
        HashMap<Character, Integer> map = new HashMap<>();
        map.put('N', 0);
        map.put('E', 1);
        map.put('W', 2);
        map.put('S', 3);

        int[] news = {0, 0, 0, 0};
        int n = s.length();

        int maxDis = 0;
        for (int i = 0; i < n; i++) {
            news[map.get(s.charAt(i))]++;
            maxDis = Math.max(computeMax(news, k), maxDis);
        }

        return maxDis;
    }
}