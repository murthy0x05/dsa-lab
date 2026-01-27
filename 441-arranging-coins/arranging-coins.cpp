class Solution {
    using ll = long long;
public:
    int arrangeCoins(int n) {
        ll low = 1, high = n;
        while (low <= high) {
            int mid = low + ((high - low) >> 1);
            ll X = (mid * 1LL * (mid + 1)) / 2;
            if (X <= n) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }

        return high;
    }
};