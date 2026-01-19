class Solution {
public:
    int maxSideLength(vector<vector<int>>& mat, int threshold) {
        int r = mat.size();
        int c = mat[0].size();

        vector<vector<int>> ps(r + 1, vector<int>(c + 1, 0));
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                ps[i + 1][j + 1] = mat[i][j] + ps[i][j + 1] + ps[i + 1][j] - ps[i][j];
            }
        }

        function<bool(int&)> feasible = [&](int& side) {
            for (int i = 0; i <= r - side; i++) {
                for (int j = 0; j <= c - side; j++) {
                    if (ps[i + side][j + side] - ps[i + side][j] - ps[i][j + side] + ps[i][j] <= threshold) {
                        return true;
                    }
                }
            }

            return false;
        };

        int result = 0;
        int low = 1, high = min(r, c);
        while (low <= high) {
            int mid = low + ((high - low) >> 1);
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