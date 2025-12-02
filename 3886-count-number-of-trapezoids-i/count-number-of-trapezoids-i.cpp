class Solution {
    using ll = long long;
    const int MOD = 1e9 + 7;
public:
    int countTrapezoids(vector<vector<int>>& points) {
        sort(points.begin(), points.end(), [](vector<int>& a, vector<int>& b) {
            if (a[1] != b[1]) {
                return a[1] < b[1];
            } else {
                return a[0] < b[0];
            }
        });

        int n = points.size();
        ll sum = 0LL;
        ll result = 0LL;
        for (int i = 1, s; i < n; i++) {
            s = 1;
            while (i < n && points[i][1] == points[i - 1][1]) {
                i++;
                s++;
            }

            if (s >= 2) {
                ll sC2 = (s * 1LL * (s - 1)) / 2;
                result = (result + ((sum % MOD) * (sC2 % MOD))) % MOD;
                sum += sC2;
            }
        }

        return result;
    }
};