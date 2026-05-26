class Solution {
public:
    int numberOfSpecialChars(string word) {
        const int N = word.size();

        vector<bool> capital(26, false), small(26, false);
        for (int i = 0; i < N; i++) {
            if (word[i] < 'a') {
                capital[word[i] - 'A'] = true;
            } else {
                small[word[i] - 'a'] = true;
            }
        }

        int result = 0;
        for (int i = 0; i < 26; i++) {
            result += capital[i] && small[i];
        }

        return result;
    }
};