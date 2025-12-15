class Solution {
    using ll = long long;
public:
    long long getDescentPeriods(vector<int>& prices) {
        int n = prices.size();

        int len = 1;
        ll result = 0;
        for (int i = 1; i < n; i++) {
            if (prices[i] + 1 == prices[i - 1]) {
                len++;
            } else {
                result += (len * 1LL * (len + 1)) >> 1;
                len = 1;
            }
        }
        
        return result + ((len * 1LL * (len + 1)) >> 1);
    }
};