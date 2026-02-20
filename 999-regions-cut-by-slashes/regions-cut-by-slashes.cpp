class Solution {
public:
    int regionsBySlashes(vector<string>& grid) {
        const int N = grid.size();

        vector<vector<char>> binary_grid(3 * N, vector<char>(3 * N, '0'));
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                if (grid[i][j] == '/') {
                    binary_grid[3 * i][3 * j + 2] = '1';
                    binary_grid[3 * i + 1][3 * j + 1] = '1';
                    binary_grid[3 * i + 2][3 * j] = '1';
                } else if (grid[i][j] == '\\') {
                    binary_grid[3 * i][3 * j] = '1';
                    binary_grid[3 * i + 1][3 * j + 1] = '1';
                    binary_grid[3 * i + 2][3 * j + 2] = '1';
                }
            }
        }
        vector<vector<bool>> visited(3 * N, vector<bool>(3 * N, false));
        vector<int> dir = {-1, 0, 1, 0, -1};
        function<void(int, int)> dfs = [&](int i, int j) {
            visited[i][j] = true;
            for (int d = 0; d < 4; d++) {
                int ni = i + dir[d];
                int nj = j + dir[d + 1];
                if (ni >= 0 && nj >= 0 && ni < (3 * N) && nj < (3 * N) && !visited[ni][nj] && binary_grid[ni][nj] == '0') {
                    dfs(ni, nj);
                }
            }
        };

        int regions = 0;
        for (int i = 0; i < 3 * N; i++) {
            for (int j = 0; j < 3 * N; j++) {
                if (binary_grid[i][j] == '0' && !visited[i][j]) {
                    dfs(i, j);
                    regions++;
                }
            }
        }

        return regions;
    }
};