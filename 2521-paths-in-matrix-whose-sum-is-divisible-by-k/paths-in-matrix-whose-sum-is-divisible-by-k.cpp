class Solution {
    // inline int solve(auto& grid, const int& k, int x, int y) {
    //     if (0 == x && 0 == y) {
    //         if (mem[x][y][grid[x][y] % k] != -1) {
    //             return mem[x][y][grid[x][y] % k];
    //         }
            
    //         int total = 

    //     }
    // }
public:
    int numberOfPaths(vector<vector<int>>& grid, int K) {
        int m = grid.size();
        int n = grid[0].size();
        int mod = 1e9 + 7;
        vector<vector<vector<int>>> dp(m, vector<vector<int>>(n, vector<int>(K, -1)));
        function<int(int,int,int)> solve = [&](int x,int y,int k){
            if(x >= m || y >= n) return 0;
            if(x == m - 1 && y == n - 1) return ((k + grid[m - 1][n - 1]) % K == 0) ? 1 : 0;
            if(dp[x][y][k] != -1) return dp[x][y][k];
            int total = solve(x + 1,y,(k + grid[x][y]) % K) + solve(x,y + 1,(k + grid[x][y]) % K);
            return dp[x][y][k] = total % mod;
        };
        return solve(0, 0, 0);
    }
};