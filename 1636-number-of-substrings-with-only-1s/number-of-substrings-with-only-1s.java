class Solution {
    final int MOD = (int)1e9 + 7;
    public int numSub(String s) {
        int n = s.length();

        int i = 0, j = 0;
        long result = 0;
        while (i < n) {
            j++;
            if (s.charAt(i) == '0') {
                i++;
            } else {
                while (j < n && s.charAt(i) == s.charAt(j)) {
                    j++;
                }

                result += ((j - i) * 1L * (j - i + 1)) / 2;
                i = j;
            }
        }

        return (int)(result % MOD);
    }
}