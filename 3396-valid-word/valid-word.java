class Solution {
    public boolean isValid(String word) {
        int n = word.length();
        if (n < 3)
            return false;
        
        boolean[] conditions = new boolean[] {false, false, false};
        HashSet<Character> vowels = new HashSet<>(
            Arrays.asList('a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U')
        );
        HashSet<Character> specialChars = new HashSet<>(
            Arrays.asList('@', '#', '$')
        );

        for (int i = 0; i < n; i++) {
            char c = word.charAt(i);
            if (vowels.contains(c)) {
                conditions[1] = true;
            } else if (specialChars.contains(c)) {
                conditions[0] = true;
            } else if (c > 'A') {
                conditions[2] = true;
            }
        }

        return !conditions[0] && conditions[1] && conditions[2];
    }
}