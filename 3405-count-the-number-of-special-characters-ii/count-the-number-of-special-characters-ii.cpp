class Solution {
public:
    int numberOfSpecialChars(string word) {
        const int N = word.size();

        vector<int> capital(26, N), small(26, -1);
        for (int i = 0; i < N; i++) {
            if (word[i] < 'a') {
                capital[word[i] - 'A'] = min(i, capital[word[i] - 'A']);
            } else {
                small[word[i] - 'a'] = i;
            }
        }
        
        int result = 0;
        for (int i = 0; i < 26; i++) {
            if (capital[i] != N && small[i] != -1 && small[i] < capital[i]) {
                result++;
            }
        }

        return result;
    }
};