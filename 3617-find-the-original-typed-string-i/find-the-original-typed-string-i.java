class Solution {
    public int possibleStringCount(String word) {
        int repeated = 0;
        for (int i = 0, len = word.length(); i < len - 1; i++) {
            if (word.charAt(i) == word.charAt(i + 1)) {
                repeated += 1;
            }
        }

        return repeated + 1;
    }
}