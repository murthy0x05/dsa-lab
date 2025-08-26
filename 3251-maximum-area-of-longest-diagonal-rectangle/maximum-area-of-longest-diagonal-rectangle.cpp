class Solution {
public:
    int areaOfMaxDiagonal(vector<vector<int>>& dimensions) {
        pair<int, int> result = {0, 0};
        for (int i = 0, n = dimensions.size(); i < n; i++) {
            int d_squared = dimensions[i][0] * dimensions[i][0] +
                            dimensions[i][1] * dimensions[i][1];
            if (result.first <= d_squared) {
                if (result.first == d_squared) {
                    result.second = max<int>(result.second, dimensions[i][0] * dimensions[i][1]);
                } else {
                    result.first = d_squared;
                    result.second = dimensions[i][0] * dimensions[i][1];
                }
            }
        }

        return result.second;
    }
};