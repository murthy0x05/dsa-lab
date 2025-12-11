class Solution {
public:
    int countCoveredBuildings(int n, vector<vector<int>>& buildings) {
        sort(buildings.begin(), buildings.end(), [](vector<int>& a, vector<int>& b) {
            if (a[0] != b[0]) {
                return a[0] < b[0];
            } else {
                return a[1] < b[1];
            }
        });

        int i = 1,
            sz = buildings.size();

        vector<pair<int, int>> y(n + 1, make_pair(INT_MAX, INT_MIN));
        for (int i = 0; i < sz; i++) {
            y[buildings[i][1]].first = min(y[buildings[i][1]].first, buildings[i][0]);
            y[buildings[i][1]].second = max(y[buildings[i][1]].second, buildings[i][0]);
        }

        int result = 0;

        while (i < sz && buildings[i][0] == buildings[i - 1][0]) i++;
        while (sz >= 2 && buildings[sz - 1][0] == buildings[sz - 2][0]) sz--;
        for (; i < sz - 1; i++) {
            if (buildings[i][0] == buildings[i - 1][0] &&
                buildings[i][0] == buildings[i + 1][0] &&
                buildings[i][0] > y[buildings[i][1]].first &&
                buildings[i][0] < y[buildings[i][1]].second) {
                result++;
            }
        }

        return result;

    }
};