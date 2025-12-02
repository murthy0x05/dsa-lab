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
        int sum = 0,
            result = 0;
        for (int i = 1, s; i < n; i++) {
            s = 1;
            while (i < n && points[i][1] == points[i - 1][1]) {
                i++;
                s++;
            }

            if (s >= 2) {
                int sC2 = ((s * 1LL * (s - 1)) / 2) % MOD;
                result = (result + (sum * 1LL * sC2)) % MOD;
                sum = (sum + sC2) % MOD;
            }
        }

        return result;
    }
};