class Solution {
    vector<int> dir = {-1, 0, 1, 0, -1};
    int n, m;
    bool isValid(int x, int y) {
        return x >= 0 && y >= 0 && x < n && y < m;
    }
    void doDFS(auto& grid, auto& visited, int x, int y) {
        visited[x][y] = true;
        for (int i = 0; i < 4; i++) {
            int nx = x + dir[i];
            int ny = y + dir[i + 1];
            if (isValid(nx, ny) && grid[nx][ny] == 1 && !visited[nx][ny]) {
                doDFS(grid, visited, nx, ny);
            }
        }
    }
public:
    int numEnclaves(vector<vector<int>>& grid) {
        this -> n = grid.size();
        this -> m = grid[0].size();

        vector<vector<bool>> visited(n, vector<bool>(m, false));
        for (int i = 0; i < n; i++) {
            if (grid[i][0] == 1 && !visited[i][0])
                doDFS(grid, visited, i, 0);
            if (grid[i][m - 1] == 1 && !visited[i][m - 1])
                doDFS(grid, visited, i, m - 1);
        }
        for (int i = 1; i < m; i++) {
            if (grid[0][i] == 1 && !visited[0][i])
                doDFS(grid, visited, 0, i);
            if (grid[n - 1][i] == 1 && !visited[n - 1][i])
                doDFS(grid, visited, n - 1, i);
        }

        int enclaves = 0;
        for (int i = 1; i < n - 1; i++) {
            for (int j = 1; j < m - 1; j++) {
                if (grid[i][j] == 1 && !visited[i][j]) {
                    enclaves += 1;
                }  
            }
        }

        return enclaves;
    }
};