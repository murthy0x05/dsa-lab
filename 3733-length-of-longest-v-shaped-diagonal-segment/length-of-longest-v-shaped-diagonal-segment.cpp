class Solution {
    typedef pair<int, int> pii;
    int r, c;
    vector<pii> dir = {{-1, -1}, {-1, 1}, {1, 1}, {1, -1}};
    bool isValid(int& i, int& j) {
        return i >= 0 && j >= 0 && i < r && j < c;
    }
    int dfs(auto& grid, int d, int i, int j, bool rotated) {
        int maxlen = 0;
        int ni, nj;

        ni = i + dir[d].first;
        nj = j + dir[d].second;
        if (isValid(ni, nj) && ((grid[i][j] == 0 || grid[i][j] == 1) ? grid[ni][nj] == 2 : grid[ni][nj] == 0)) {
            maxlen = max<int>(maxlen, dfs(grid, d, ni, nj, rotated));
        }

        if (!rotated) {
            d = (d + 1) % 4;
            ni = i + dir[d].first;
            nj = j + dir[d].second;
            if (isValid(ni, nj) && ((grid[i][j] == 0) ? grid[ni][nj] == 2 : grid[ni][nj] == 0)) {
                maxlen = max<int>(maxlen, dfs(grid, d, ni, nj, true));
            }
            d = (d - 1) % 4;
        }

        return maxlen + 1;
    }
public:
    int lenOfVDiagonal(vector<vector<int>>& grid) {
        this -> r = grid.size();
        this -> c = grid[0].size();

        int maxlen = 0, len = 0;
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                if (grid[i][j] == 1) {
                    for (int d = 0; d < 4; d++) {
                        int ni = i + dir[d].first;
                        int nj = j + dir[d].second;
                        if (isValid(ni, nj) && grid[ni][nj] == 2) {
                            len = max<int>(len, dfs(grid, d, ni, nj, false));
                        }
                        // cout << i << ' ' << j << ' ' << d << ' ' << maxlen << endl;
                    }
                    maxlen = max<int>(maxlen, len + 1);
                }
            }
        }

        return maxlen;
    }
};