class Solution {
public:
    vector<vector<int>> reconstructMatrix(int upper, int lower, vector<int>& colsum) {
        int m = colsum.size();
        vector<vector<int>> matrix(2, vector<int>(m, 0));
        
        for (int i = 0; i < m; i++) {
            if (colsum[i] == 2) {
                matrix[0][i] = 1;
                matrix[1][i] = 1;
                upper--;
                lower--;
            } else if (colsum[i] == 1) {
                if (upper > lower) {
                    matrix[0][i] = 1;
                    upper--;
                } else {
                    matrix[1][i] = 1;
                    lower--;
                }
            }
        }

        if (upper == 0 && 0 == lower) {
            return matrix;
        } else {
            return {};
        }
    }
};