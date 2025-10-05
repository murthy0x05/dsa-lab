// class Solution {
//     int r, c;
//     int fillPacific(vector<vector<int>>& heights, vector<vector<int>>& pacific, int i, int j) {
//         if (i == 0 || j == 0) {
//             pacific[i][j] = 1;
//         }
        
//         if (pacific[i][j] != -1) {
//             return pacific[i][j];
//         }

//         pacific[i][j] = 0;
//         if (heights[i][j] >= heights[i - 1][j]) {
//             pacific[i][j] = max<int>(pacific[i][j], fillPacific(heights, pacific, i - 1, j));
//         }
//         if (heights[i][j] >= heights[i][j - 1]) {
//             pacific[i][j] = max<int>(pacific[i][j], fillPacific(heights, pacific, i, j - 1));
//         }
//         if (i < r - 1 && heights[i][j] >= heights[i + 1][j]) {
//             pacific[i][j] = max<int>(pacific[i][j], fillPacific(heights, pacific, i + 1, j));
//         }
//         if (j < c - 1 && heights[i][j] >= heights[i][j + 1]) {
//             pacific[i][j] = max<int>(pacific[i][j], fillPacific(heights, pacific, i, j + 1));
//         }

//         return pacific[i][j];
//     }
//     int fillAtlantic(vector<vector<int>>& heights, vector<vector<int>>& atlantic, int i, int j) {
//         if (i == r - 1 || j == c - 1) {
//             atlantic[i][j] = 1;
//         }
        
//         if (atlantic[i][j] != -1) {
//             return atlantic[i][j];
//         }

//         atlantic[i][j] = 0;
//         if (i >= 1 && heights[i][j] >= heights[i - 1][j]) {
//             atlantic[i][j] = max<int>(atlantic[i][j], fillAtlantic(heights, atlantic, i - 1, j));
//         }
//         if (j >= 1 && heights[i][j] >= heights[i][j - 1]) {
//             atlantic[i][j] = max<int>(atlantic[i][j], fillAtlantic(heights, atlantic, i, j - 1));
//         }
//         if (heights[i][j] >= heights[i + 1][j]) {
//             atlantic[i][j] = max<int>(atlantic[i][j], fillAtlantic(heights, atlantic, i + 1, j));
//         }
//         if (heights[i][j] >= heights[i][j + 1]) {
//             atlantic[i][j] = max<int>(atlantic[i][j], fillAtlantic(heights, atlantic, i, j + 1));
//         }

//         return atlantic[i][j];
//     }
// public:
//     vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
//         r = heights.size();
//         c = heights[0].size();

//         vector<vector<int>> pacific(r, vector<int>(c, -1)),
//                             atlantic(r, vector<int>(c, -1));
//         vector<vector<int>> result;

//         for (int i = 0; i < r; i++) {
//             for (int j = 0; j < c; j++) {
//                 if (fillPacific(heights, pacific, i, j) == 1 &&
//                     fillAtlantic(heights, atlantic, i, j) == 1) {
//                         result.push_back({i, j});
//                 }
//             }
//         }

//         return result;
//     }
// };

class Solution {
public:
    int m, n;
    vector<vector<int>> directions = {{1,0}, {-1,0}, {0,1}, {0,-1}};

    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        m = heights.size();
        n = heights[0].size();

        vector<vector<bool>> pacific(m, vector<bool>(n, false));
        vector<vector<bool>> atlantic(m, vector<bool>(n, false));

        for (int j = 0; j < n; j++) dfs(0, j, heights, pacific);
        for (int i = 0; i < m; i++) dfs(i, 0, heights, pacific);

        for (int j = 0; j < n; j++) dfs(m-1, j, heights, atlantic);
        for (int i = 0; i < m; i++) dfs(i, n-1, heights, atlantic);

        vector<vector<int>> result;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (pacific[i][j] && atlantic[i][j]) {
                    result.push_back({i, j});
                }
            }
        }

        return result;
    }

    void dfs(int i, int j, vector<vector<int>>& heights, vector<vector<bool>>& visited) {
        visited[i][j] = true;
        
        for (auto& d : directions) {
            int x = i + d[0], y = j + d[1];
            
            if (x < 0 || x >= m || y < 0 || y >= n) continue;
            if (visited[x][y]) continue;
            if (heights[x][y] < heights[i][j]) continue;
            
            dfs(x, y, heights, visited);
        }
    }
};