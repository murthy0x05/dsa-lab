class Solution {
private:
    int rows, cols;
    vector<int> dir;
    inline bool isValid(int row, int col) {
        return row >= 0 && col >= 0 && row < rows && col < cols;
    }
    inline int getArea(vector<vector<int>>& grid, vector<vector<bool>>& visited, int row, int col) {
        int area = 1;
        visited[row][col] = true;
        for (int i = 0; i < 4; i++) {
            int newRow = row + dir[i];
            int newCol = col + dir[i+1];
            if (isValid(newRow, newCol) && grid[newRow][newCol] == 1 && !visited[newRow][newCol]) {
                area += getArea(grid, visited, newRow, newCol);
            }
        }

        return area;
    }
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        this -> rows = grid.size();
        this -> cols = grid[0].size();
        vector<vector<bool>> visited(rows, vector<bool>(cols, false));
        dir = {-1, 0, 1, 0, -1};
        
        int maxArea = 0;
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (grid[i][j] == 1 && !visited[i][j]) {
                    maxArea = std::max(maxArea, getArea(grid, visited, i, j));
                }
            }
        }

        return maxArea;
    }
};