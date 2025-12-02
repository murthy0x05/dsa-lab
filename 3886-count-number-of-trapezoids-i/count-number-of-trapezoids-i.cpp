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
        ll prev = 0LL;
        ll sum = 0LL;
        ll result = 0LL;
        for (int i = 1, curr; i < n; i++) {
            curr = 1;
            while (i < n && points[i][1] == points[i - 1][1]) {
                i++;
                curr++;
            }

            if (curr >= 2) {
                ll nC2 = (curr * 1LL * (curr - 1)) / 2;
                result = (result + ((sum % MOD) * (nC2 % MOD))) % MOD;
                sum += nC2;
            }
        }

        return result;
    }
};