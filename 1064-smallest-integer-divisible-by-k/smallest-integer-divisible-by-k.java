class Solution {
    public int smallestRepunitDivByK(int k) {
        if (k % 2 == 0 || k % 5 == 0) return -1;
        
        int mod = 0;
        for (int i = 1; i <= k; i++) {
            mod = (mod * 10 + 1) % k;
            if (0 == mod) return i;
        }

        return -1;
    }
}