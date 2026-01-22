class Solution {
public:
    vector<vector<int>> matrixBlockSum(vector<vector<int>>& mat, int k) {
        int rows = mat.size();
        int cols = mat[0].size();
        
        vector<vector<int>> ps(rows + 1, vector<int>(cols + 1));
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                ps[i + 1][j + 1] = (ps[i][j + 1] + ps[i + 1][j] - ps[i][j]) + mat[i][j];
            }
        }

        vector<vector<int>> result(rows, vector<int>(cols));
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                int rs = max(0, i - k), re = min(rows - 1, i + k);
                int cs = max(0, j - k), ce = min(cols - 1, j + k);
                result[i][j] = ps[re + 1][ce + 1] - ps[rs][ce + 1] - ps[re + 1][cs] + ps[rs][cs];
            }
        }

        return result;
    }
};