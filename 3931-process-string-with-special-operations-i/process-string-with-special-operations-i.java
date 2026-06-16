class Solution {
    public String processStr(String s) {
        final int N = s.length();

        StringBuilder sb = new StringBuilder();
        for (int i = 0; i < N; i++) {
            if (s.charAt(i) == '*') {
                if (sb.length() > 0) {
                    sb.setLength(sb.length() - 1);
                }
            } else if (s.charAt(i) == '#') {
                sb.append(sb.toString());
            } else if (s.charAt(i) == '%') {
                sb.reverse();
            } else {
                sb.append(s.charAt(i));
            }
        }

        return sb.toString();
    }
}