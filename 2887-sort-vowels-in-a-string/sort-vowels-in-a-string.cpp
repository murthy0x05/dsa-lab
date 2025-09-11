class Solution {
public:
    string sortVowels(string s) {
        int n = s.size();
        int counts[256] = {0};
        
        vector<bool> isVowel(58, false);
        string vowels = "aeiouAEIOU";
        for (const char& vowel: vowels) {
            isVowel[vowel - 'A'] = true;
        }

        for (char& c: s) {
            if (isVowel[c - 'A']) {
                counts[c]++;
                c = '*';
            }
        }

        int ptr = 'A';
        for (char& c: s) {
            if (c == '*') {
                while (ptr < 'z' + 1 && counts[ptr] == 0) ptr++;
                c = (char)ptr;
                counts[ptr]--;
            }
        }

        cout << (int)'z' << endl;

        return s;
    }
};