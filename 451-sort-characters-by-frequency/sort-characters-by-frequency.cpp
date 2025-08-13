class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char, int> freq;
        for (const char& c: s) {
            if (isdigit(c)) {
                freq[c]++;
            } else {
                freq[c]++;
            }
        }

        sort(s.begin(), s.end(), [&freq](const char a, const char b) {
            if (freq[a] != freq[b]) {
                return freq[a] > freq[b];
            } else {
                return a < b;
            }
        });

        return s;
    }
};