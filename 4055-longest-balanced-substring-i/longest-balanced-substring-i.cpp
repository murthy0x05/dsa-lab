class Solution {
public:
    int longestBalanced(string s) {
        const int N = s.size();
        if (N == 1) return 1;

        int result = 0;
        for (int i = 0; i < N; i++) {
            if (N - i <= result) {
                break;
            }

            vector<int> counts(26, 0);
            int unique = 0, maxFreq = 0;
            for (int j = i; j < N; j++) {
                counts[s[j] - 'a']++;
                unique += counts[s[j] - 'a'] == 1;
                maxFreq = max(maxFreq, counts[s[j] - 'a']);

                if (unique * maxFreq == (j - i + 1)) {
                    result = max(result, j - i + 1);
                }
            }
        }

        return result;
    }
};