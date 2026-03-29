class Solution {
public:
    bool checkStrings(string s1, string s2) {
        const int N = s1.size();

        vector<int> occE(26, 0),
                    occO(26, 0);
        for (int i = 0; i < N; i++) {
            if (i & 1) {
                occO[s1[i] - 'a']++;
                occO[s2[i] - 'a']--;
            } else {
                occE[s1[i] - 'a']++;
                occE[s2[i] - 'a']--;
            }
        }

        for (int i = 0; i < 26; i++) {
            if (occO[i] || occE[i]) return false;
        }

        return true;
    }
};