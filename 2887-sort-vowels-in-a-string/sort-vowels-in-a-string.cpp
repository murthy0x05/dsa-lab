class Solution {
    unordered_set<char> vowels;
public:
    string sortVowels(string s) {
        int n = s.size();
        int counts[256] = {0};
        
        vowels = {'A', 'E', 'I', 'O', 'U', 'a', 'e', 'i', 'o', 'u'};

        for (char& c: s) {
            if (vowels.count(c) > 0) {
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

        return s;
    }
};