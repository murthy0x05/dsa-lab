class Solution {
public:
    bool containsCycle(vector<vector<char>>& grid) {
        const int R = grid.size(),
                  C = grid[0].size();
        
        vector<int> dir = {-1, 0, 1, 0, -1};
        vector<vector<bool>> visited(R, vector<bool>(C, false));
        function<bool(int, int, int, int)> f = [&] (int i, int j, int pi, int pj) {
            visited[i][j] = true;

            for (int d = 0; d < 4; d++) {
                int ni = i + dir[d], nj = j + dir[d + 1];
                if (ni >= 0 && nj >= 0 && ni < R && nj < C) {
                    if (ni == pi && nj == pj) {
                        continue;
                    }
                    if (grid[ni][nj] == grid[i][j]) {
                        if (visited[ni][nj]) {
                            return true;
                        } else if (f(ni, nj, i, j)) {
                            return true;
                        }
                    }
                }
            }

            return false;
        };

        for (int i = 0; i < R; i++) {
            for (int j = 0; j < C; j++) {
                if (!visited[i][j] && f(i, j, -1, -1)) {
                    return true;
                }
            }
        }

        return false;
    }
};