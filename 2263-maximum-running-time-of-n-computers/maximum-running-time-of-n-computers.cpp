class Solution {
    using ll = long long;
public:
    long long maxRunTime(int k, vector<int>& batteries) {
        ll total = 0;
        for (int b : batteries) total += b;

        ll low = 0, high = total / k;
        
        auto feasible = [&](ll mid) -> bool {
            ll time = 0;
            for (ll b : batteries)
                time += min(b, mid);
            return time >= mid * k;
        };

        ll result = 0;
        while (low <= high) {
            ll mid = low + (high - low) / 2;
            if (feasible(mid)) {
                result = mid;
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }

        return result;
    }
};
