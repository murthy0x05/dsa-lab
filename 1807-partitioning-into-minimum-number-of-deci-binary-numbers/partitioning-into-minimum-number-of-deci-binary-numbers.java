class Solution {
    public int minPartitions(String n) {
        int maxVal = 0;
        for (final char c: n.toCharArray()) {
            maxVal = Math.max(maxVal, c - '0');
        }

        return maxVal;
    }
}