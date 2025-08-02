class Solution {
    int rows, cols;
    vector<vector<bool>> visited;
    vector<int> dir = {-1, 0, 1, 0, -1};
    vector<vector<int>> mem;
    bool isValid(int x, int y) {
        return x >= 0 && y >= 0 && x < rows && y < cols;
    }
    int doDFS(auto& matrix, int x, int y) {
        if (mem[x][y] != -1) {
            return mem[x][y];
        }
        int longestPath = 1;
        visited[x][y] = true;
        for (int i = 0; i < 4; i++) {
            int nx = x + dir[i];
            int ny = y + dir[i + 1];
            if (isValid(nx, ny) && matrix[nx][ny] > matrix[x][y] && !visited[nx][ny]) {
                longestPath = max<int>(longestPath, 1 + doDFS(matrix, nx, ny));
            }
        }
        visited[x][y] = false;

        return mem[x][y] = longestPath;
    }
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        this -> rows = matrix.size();
        this -> cols = matrix[0].size();
        visited.assign(rows, vector<bool>(cols, false));
        mem.resize(rows, vector<int>(cols, -1));

        int longestPath = 1;
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                longestPath = max<int>(longestPath, doDFS(matrix, i, j));
            }
        }

        return longestPath;
    }
};