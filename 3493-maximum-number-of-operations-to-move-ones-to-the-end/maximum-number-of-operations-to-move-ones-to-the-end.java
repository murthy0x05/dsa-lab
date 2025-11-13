class Solution {
    public int maxOperations(String s) {
        int n = s.length();

        int ops = 0, po = s.charAt(0) - '0';
        for (int i = 1; i < n; i++) {
            if (s.charAt(i) == '1') {
                if (s.charAt(i) != s.charAt(i - 1)) {
                    ops += po;
                }
                po++;
            }
        }

        return (s.charAt(n - 1) == '1') ? ops : ops + po;
    }
}