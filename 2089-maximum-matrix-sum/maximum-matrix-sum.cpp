class Solution {
    using ll = long long;
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        int r = matrix.size();
        int c = matrix[0].size();

        bool cancels = true;
        int globalMin = abs(matrix[0][0]);
        ll total = 0LL;
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                if (matrix[i][j] < 0) {
                    cancels = cancels ^ 1;
                    globalMin = min(globalMin, -matrix[i][j]);
                    total -= matrix[i][j];
                } else {
                    globalMin = min(globalMin, matrix[i][j]);
                    total += matrix[i][j];
                }
            }
        }
        
        return cancels ? total : total - 2 * globalMin;
    }
};