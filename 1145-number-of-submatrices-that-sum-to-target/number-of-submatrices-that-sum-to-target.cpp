class Solution {
public:
    inline int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target) {
        int rows = matrix.size();
        int cols = matrix[0].size();

        vector<vector<int>> ps(101, vector<int>(101));
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                ps[i + 1][j + 1] = matrix[i][j] + ps[i][j + 1] + ps[i + 1][j] - ps[i][j];
            }
        }

        int result = 0;
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                for (int k1 = 0; k1 <= i; k1++) {
                    for (int k2 = 0; k2 <= j; k2++) {
                        if ((ps[i + 1][j + 1] - target) ==  ps[i - k1][j + 1] + ps[i + 1][j - k2] - ps[i - k1][j - k2]) {
                            // cout << i << ' ' << j << endl;
                            // cout << k1 << ' ' << k2 << endl;
                            // cout << "---cc---" << endl;
                            result++;
                        }
                    }
                }
            }
        }

        return result;
    }
};