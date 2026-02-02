class Solution {
    using pii = pair<int, int>;
public:
    int orangesRotting(vector<vector<int>>& grid) {
        const int r = grid.size(),
                  c = grid[0].size();
        vector<int> dir = {-1, 0, 1, 0, -1};

        queue<pii> q;
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                if (grid[i][j] == 2) {
                    q.push(make_pair(i, j));
                }
            }
        }

        int result = 0;
        while (!q.empty()) {
            for (int ls = q.size(); ls; ls--) {
                pii curr = q.front(); q.pop();

                for (int d = 0; d < 4; d++) {
                    int ni = curr.first + dir[d];
                    int nj = curr.second + dir[d + 1];
                    if (ni >= 0 && nj >= 0 && ni < r && nj < c && grid[ni][nj] == 1) {
                        grid[ni][nj] = 2;
                        q.push(make_pair(ni, nj));
                    }
                }
            }

            result += !q.empty();
        }

        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                if (grid[i][j] == 1) {
                    return -1;
                }
            }
        }

        return result;
    }
};