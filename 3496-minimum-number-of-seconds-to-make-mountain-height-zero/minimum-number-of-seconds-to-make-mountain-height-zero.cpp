class Solution {
    using ll = long long;
public:
    long long minNumberOfSeconds(int mountainHeight, vector<int>& workerTimes) {
        const int N = workerTimes.size();

        function<bool(const ll&, ll)> feasible = [&] (const ll& sec, ll X) {
            for (int i = 0; i < N; i++) {
                if (X <= 0) {
                    return true;
                }
                ll low = 0, high = X;
                while (low <= high) {
                    ll mid = low + ((high - low) >> 1);
                    if ((workerTimes[i] * 1LL * ((mid * mid + mid) / 2)) <= sec) {
                        low = mid + 1;
                    } else {
                        high = mid - 1;
                    }
                }

                X -= high;
            }

            return X <= 0;
        };

        ll low = 1, high = 1e18;
        while (low <= high) {
            ll mid = low + ((high - low) >> 1);
            if (feasible(mid, (ll)mountainHeight)) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        return low;
    }
};