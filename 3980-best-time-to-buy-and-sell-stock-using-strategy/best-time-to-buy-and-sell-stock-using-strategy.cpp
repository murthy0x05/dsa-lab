class Solution {
    #define ll long long
public:
    long long maxProfit(vector<int>& prices, vector<int>& strategy, int k) {
        int n = prices.size();
        vector<ll> x(n + 1, 0);
        vector<ll> y(n + 1, 0);
        for (int i = 0; i < n; i++) {
            x[i + 1] = x[i] + prices[i];
            y[i + 1] = y[i] + (prices[i] * strategy[i]);
        }

        long long ans = y[n];
        for (int i = 0; i < n - k + 1; i++) {
            ll curr = 0;
            curr += y[i];
            curr += x[i + k] - x[i + (k / 2)];
            curr += y[n] - y[i + k];
            ans = max<ll>(ans, curr);
        }

        return ans;
    }
};