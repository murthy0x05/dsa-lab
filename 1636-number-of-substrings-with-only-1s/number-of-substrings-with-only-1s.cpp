class Solution {
    const int MOD = 1e9 + 7;
    using ll = long long;
public:
    int numSub(string s) {
        int n = s.size();

        int i = 0, j = 0;
        ll result = 0;
        while (i < n) {
            j++;
            if (s[i] == '0') {
                i++;
            } else {
                while (j < n && s[i] == s[j]) {
                    j++;
                }

                result += ((j - i) * 1LL * (j - i + 1)) / 2;
                i = j;
            }
        }

        return result % MOD;
    }
};