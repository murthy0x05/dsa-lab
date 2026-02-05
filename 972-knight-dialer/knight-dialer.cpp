class Solution {
    static constexpr int MOD = 1e9 + 7;
public:
    int knightDialer(int n) {
        vector<vector<int>> grid = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}, {11, 0, 11}};
        vector<vector<int>> dir = {{-2, -1}, {-1, -2}, {-2, 1}, {-1, 2},
                                   {1, -2}, {2, -1}, {2, 1}, {1, 2}};
        vector<vector<int>> mem(n, vector<int>(12, -1)); 
        for (int i = 0; i < n; i++)
            mem[i][11] = 0;
        
        function<int(int&, int&, int)> dfs = [&](const int& i, const int& j, int pos) {
            if (pos >= (n - 1)) {
                return mem[pos][grid[i][j]] = grid[i][j] < 10;
            }
            if (mem[pos][grid[i][j]] != -1) {
                return mem[pos][grid[i][j]];
            }

            int ways = 0;
            for (int d = 0; d < 8; d++) {
                int ni = i + dir[d][0];
                int nj = j + dir[d][1];
                if (ni >= 0 && nj >= 0 && ni < 4 && nj < 3) {
                    ways = (0LL + ways + dfs(ni, nj, pos + 1)) % MOD;
                }
            }

            return mem[pos][grid[i][j]] = ways;
        };

        int result = 0;
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 3; j++) {
                result = (0LL + result + dfs(i, j, 0)) % MOD;
            }
        }

        return result;
    }
};