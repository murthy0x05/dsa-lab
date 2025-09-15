class Solution {
    public int canBeTypedWords(String text, String brokenLetters) {
        boolean broken[] = new boolean[26];

        for (final char bl: brokenLetters.toCharArray()) {
            broken[bl - 'a'] = true;
        }

        int result = 0;
        for (String word: text.split(" ")) {
            result++;
            for (final char l: word.toCharArray()) {
                if (broken[l - 'a']) {
                    result--;
                    break;
                }
            }
        }

        return result;
    }
}