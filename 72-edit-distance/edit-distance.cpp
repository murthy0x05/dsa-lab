class Solution {
public:
    int minDistance(string &s1, string &s2) {
        int n = s1.size(), m = s2.size();

        vector<int> prev(m + 1), curr(m + 1);
        for (int i = 0; i <= m; i++)
            prev[i] = i;
        
        for (int i = 1; i <= n; i++) {
            curr[0] = i;
            for (int j = 1; j <= m; j++) {
                if (s1[i - 1] == s2[j - 1]) {
                    curr[j] = prev[j - 1];
                } else {
                    curr[j] = 1 + min({
                        prev[j], // case of removal
                        curr[j - 1], // case of insertion
                        prev[j-1] // case of replace
                    });
                }
            }
            prev = curr;
        }

        return prev[m];
    }
};