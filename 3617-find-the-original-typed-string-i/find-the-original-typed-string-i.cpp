class Solution {
public:
    int possibleStringCount(string word) {
        int repeated = 0;
        for (int i = 0, len = word.length(); i < len - 1; i++) {
            if (word[i] == word[i + 1]) {
                repeated += 1;
            }
        }

        return repeated + 1;
    }
};