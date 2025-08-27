class Solution {
public:
    int diagonalSum(vector<vector<int>>& mat) {
        int n = mat.size();
        int result = 0;

        for (int i = 0; i < n; i++) {
            result += mat[i][i];
            result += mat[i][n - i - 1];
        }

        return (n & 1) ? (result - mat[n / 2][n / 2]) : result;
    }
};