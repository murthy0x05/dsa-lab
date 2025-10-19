class Solution {
    private int n;
    private String smallest;
    Set<String> seen = null;
    void solve(String s, final int a, final int b) {
        if (!seen.add(s)) {
            return ;
        }
        if (s.compareTo(smallest) < 0) {
            smallest = s;
        }

        StringBuilder s1 = new StringBuilder(s);
        for (int i = 1; i < n; i += 2) {
            s1.setCharAt(i, (char) (((s.charAt(i) - '0' + a) % 10) + '0'));
        }
        solve(s1.toString(), a, b);
        String s2 = s.substring(s.length() - b) + s.substring(0, s.length() - b);
        solve(s2, a, b);
    }
    public String findLexSmallestString(String s, int a, int b) {
        this.smallest = s;
        this.n = s.length();
        seen = new HashSet<>();

        solve(s, a, b);
        return smallest;
    }
}