class Solution {
    public int maxFreqSum(String s) {
        int n = s.length();

        int[] counts = new int[26];
        Arrays.fill(counts, 0);

        for (final char c: s.toCharArray()) {
            counts[c - 'a']++;
        }

        int maxVowel = 0, maxCons = 0;
        for (int i = 0; i < 26; i++) {
            if (i == 'a' - 'a' || i == 'e' - 'a' || i == 'i' - 'a' || i == 'o' - 'a' || i == 'u' - 'a') {
                maxVowel = Math.max(maxVowel, counts[i]);
            } else {
                maxCons = Math.max(maxCons, counts[i]);
            }
        }

        return maxVowel + maxCons;
    }
}