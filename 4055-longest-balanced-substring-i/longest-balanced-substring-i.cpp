class Solution {
public:
    int longestBalanced(string s) {
        const int N = s.size();
        if (N == 1) return 1;

        int result = 0;
        for (int i = 0; i < N; i++) {
            vector<int> counts(26, 0);
            for (int j = i; j >= 0; j--) {
                counts[s[j] - 'a']++;
                bool flag = true;
                for (int k = 0; k < 26; k++) {
                    if (counts[k] != 0 && counts[s[j] - 'a'] != counts[k]) {
                        flag = false;
                    }
                }

                if (flag) {
                    result = max(result, i - j + 1);
                }
            }
        }

        return result;
    }
};