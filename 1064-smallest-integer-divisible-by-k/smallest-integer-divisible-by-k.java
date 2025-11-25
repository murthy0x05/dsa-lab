class Solution {
    public int smallestRepunitDivByK(int k) {
        int mod = 0;
        for (int i = 1; i <= k; i++) {
            mod = (mod * 10 + 1) % k;
            if (0 == mod) return i;
        }

        return -1;
    }
}