class Solution {
    public int maxDistinct(String s) {
        final int N = s.length();

        boolean[] freq = new boolean[26];
        for (int i = 0; i < N; i++) {
            freq[s.charAt(i) - 'a'] = true;
        }

        int result = 0;
        for (final boolean isPresent: freq) {
            if (isPresent) result++;
        }

        return result;
    }
}