class Solution {
public:
    int latestDayToCross(int r, int c, vector<vector<int>>& cells) {
        vector<int> dir = {-1, 0, 1, 0, -1};

        function<bool(vector<vector<int>>&, int, int)> dfs = [&](vector<vector<int>>& matrix, int x, int y) {
            if (x == r - 1) return true;

            matrix[x][y] = -1;
            for (int d = 0; d < 4; d++) {
                int nx = x + dir[d],
                    ny = y + dir[d + 1];
                if (nx >= 0 && nx < r && ny >= 0 && ny < c &&
                    matrix[nx][ny] == 0 && dfs(matrix, nx, ny)) {
                    return true;
                }
            }

            return false;
        };
        function<bool(int&)> feasible = [&](int& day) {
            vector<vector<int>> matrix(r, vector<int>(c, 0));
            for (int i = 0; i < day; i++) {
                matrix[cells[i][0] - 1][cells[i][1] - 1] = 1;
            }

            for (int j = 0; j < c; j++) {
                if (matrix[0][j] == 0 && dfs(matrix, 0, j)) {
                    return true;
                }
            }

            return false;
        };

        int low = 0, high = r * c;
        int result = 0;
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