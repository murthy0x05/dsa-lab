class Solution {
    typedef long long ll;
    int n;
    bool feasible(vector<ll>& df, vector<ll>& added, const int& r, const int& k, ll& mid) {
        for (int i = 0; i < n + 2; i++) {
            added[i] = 0;
        }

        ll i = 0, more = k;
        while (i < n) {
            added[i + 1] += added[i];
            if (df[i] + added[i + 1] >= mid) {
                i++;
            } else {
                ll built = mid - (df[i] + added[i + 1]);
                if (built > more) {
                    return false;
                } else {
                    more -= built;
                    added[i + 1] += built;
                    added[min<ll>(n + 1, i + 2 * r + 2)] -= built;
                    i++;
                }
            }
        }

        return i == n;
    }
public:
    long long maxPower(vector<int>& stations, int r, int k) {
        this -> n = stations.size();

        vector<ll> df(n + 1, 0);
        vector<ll> added(n + 2, 0);
        for (int i = 0; i < n; i++) {
            df[max(0, i - r)] += stations[i];
            df[min(n, i + r + 1)] -= stations[i];
        }

        ll low = stations[0], high = k + stations[0];
        for (int i = 1; i < n; i++) {
            df[i] += df[i - 1];
            low = min<ll>(low, stations[i]);
            high += stations[i];
        }

        ll result = low;
        while (low <= high) {
            ll mid = low + ((high - low) >> 1);
            if (feasible(df, added, r, k, mid)) {
                result = mid;
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }

        for (int i = 0; i <= n; i++) {
            cout << df[i] << ' ';
        }
        cout << endl;

        return result;
    }
};