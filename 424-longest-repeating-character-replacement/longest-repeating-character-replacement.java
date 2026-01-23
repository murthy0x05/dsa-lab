class Solution {
    public int characterReplacement(String s, int k) {
        int n = s.length();

        int len = 1;
        int[] counts = new int[26];
        for (int l = 0, r = 0, f = 0; r < n; r++) {
            counts[s.charAt(r) - 'A']++;
            f = Math.max(f, counts[s.charAt(r) - 'A']);
            if ((r - l + 1) - f > k) {
                counts[s.charAt(l) - 'A']--;
                l++;
            }

            len = Math.max(len, r - l + 1);
        }

        return len;
    }
}