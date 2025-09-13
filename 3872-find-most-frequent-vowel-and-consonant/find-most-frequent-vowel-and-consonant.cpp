class Solution {
public:
    int maxFreqSum(string s) {
        int counts[26] = {0};

        for (const char& c: s) {
            counts[c - 'a']++;
        }

        int mv = 0, mc = 0;
        for (int i = 0; i < 26; i++) {
            if (i == 'a' - 'a' || i == 'e' - 'a' || i == 'i' - 'a' || i == 'o' - 'a' || i == 'u' - 'a') {
                mv = max<int>(mv, counts[i]);
            } else {
                mc = max<int>(mc, counts[i]);
            }
        }

        return mv + mc;
    }
};