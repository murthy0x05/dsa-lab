class Solution {
    #define ll long long
    const int MOD = 1e9 + 7;
public:
    vector<int> productQueries(int n, vector<vector<int>>& queries) {
        vector<int> powers;

        int power = 1;
        for (int bit = 0; bit < 30; bit++) {
            if (n & (1 << bit)) {
                powers.push_back(power);
            }
            power *= 2;
        }

        vector<int> ans;
        for (auto& query: queries) {
            ll product = 1;
            for (int i = query[0]; i <= query[1]; i++) {
                product = (product * 1LL * powers[i]) % MOD;
            }
            ans.push_back(product);
        }

        return ans;
    }
};