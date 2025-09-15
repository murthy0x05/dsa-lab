class Solution {
public:
    int canBeTypedWords(string text, string brokenLetters) {
        stringstream ss(text);
        bool broken[26] = {false};

        for (const char& bl: brokenLetters) {
            broken[bl - 'a'] = true;
        }

        int result = 0;
        for (string word; ss >> word;) {
            result++;
            for (const char& l: word) {
                if (broken[l - 'a']) {
                    result--;
                    break;
                }
            }
        }

        return result;
    }
};