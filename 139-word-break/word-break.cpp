class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        const int N = s.size(),
                  M = wordDict.size();
        
        unordered_set<string> seen(wordDict.begin(), wordDict.end());
        vector<bool> dp(N + 1, false); dp[0] = true;
        for (int i = 0; i < N; i++) {
            for (int j = i; j >= 0; j--) {
                if (dp[j] && seen.count(s.substr(j, i - j + 1))) {
                    dp[i + 1] = true;
                    break;
                }
            }
        }

        return dp[N];
    }
};