class Solution {
public:
    int numberOfPairs(vector<vector<int>>& points) {
        int n = points.size();
        sort(points.begin(), points.end(), [](const auto& a, const auto& b) {
            if (a[0] != b[0]) {
                return a[0] < b[0];
            } else {
                return a[1] > b[1];
            }
        });

        int result = 0;
        for (int i = 0; i < n; i++) {
            int y = INT_MIN;
            for (int j = i + 1; j < n; j++) {
                if (points[i][1] >= points[j][1] && points[j][1] > y) {
                    result++;
                    y = points[j][1];
                }
            }
        }

        return result;
    }
};