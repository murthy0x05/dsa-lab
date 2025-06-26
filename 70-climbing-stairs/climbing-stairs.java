class Solution {
    public int climbStairs(int n) {
        int i = 1, j = 2, k = i + j;
        if (n - 3 < 0) return n;
        n -= 3;
        while (n > 0) {
            j = j ^ k ^ (k = j);
            i = i ^ k ^ (k = i);
            k = i + j; n -= 1;
        }
        return k;
    }
}