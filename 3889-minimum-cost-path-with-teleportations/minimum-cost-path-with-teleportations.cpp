class Solution {
public:
    int minCost(vector<vector<int>>& grid, int K) {
        const int r = grid.size(),
                  c = grid[0].size(),
                  INF = (r + c - 2) * 10000 + 1;

        vector<vector<int>> prev(r, vector<int>(c, INF)),
                            curr(r, vector<int>(c, INF));
        
        prev[0][0] = 0;
        for (int i = 1; i < r; i++) 
            prev[i][0] = grid[i][0] + prev[i - 1][0];
        for (int j = 1; j < c; j++) 
            prev[0][j] = grid[0][j] + prev[0][j - 1];
        for (int i = 1; i < r; i++) {
            for (int j = 1; j < c; j++) {
                prev[i][j] = grid[i][j] + min(prev[i - 1][j], prev[i][j - 1]);
            }
        }
        
        vector<int> ids(r * c);
        iota(ids.begin(), ids.end(), 0);
        // sort(ids.begin(), ids.end(), [&](const int& a, const int& b) {
        //     int ra = a / c, ca = a % c;
        //     int rb = b / c, cb = b % c;
        //     if (grid[ra][ca] != grid[rb][cb]) {
        //         return grid[ra][ca] > grid[rb][cb];
        //     } else {
        //         return prev[ra][ca] < prev[rb][cb];
        //     }
        // });

        for (int k = 1; k <= K; k++) {
            sort(ids.begin(), ids.end(), [&](const int& a, const int& b) {
                int ra = a / c, ca = a % c;
                int rb = b / c, cb = b % c;
                if (grid[ra][ca] != grid[rb][cb]) {
                    return grid[ra][ca] > grid[rb][cb];
                } else {
                    return prev[ra][ca] < prev[rb][cb];
                }
            });

            int Min = INF;
            for (const int& id: ids) {
                int i = id / c, j = id % c;
                Min = min(Min, prev[i][j]);
                curr[i][j] = Min;
            }
            prev = curr;

            for (int i = 1; i < r; i++) 
                prev[i][0] = min(prev[i][0], grid[i][0] + prev[i - 1][0]);
            for (int j = 1; j < c; j++) 
                prev[0][j] = min(prev[0][j], grid[0][j] + prev[0][j - 1]);
            for (int i = 1; i < r; i++) {
                for (int j = 1; j < c; j++) {
                    prev[i][j] = min(prev[i][j], grid[i][j] + min(prev[i - 1][j], prev[i][j - 1]));
                }
            }
        }

        return prev.back().back();
    }
};