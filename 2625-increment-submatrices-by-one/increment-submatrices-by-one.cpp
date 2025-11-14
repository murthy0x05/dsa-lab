class Solution {
public:
    vector<vector<int>> rangeAddQueries(int n, vector<vector<int>>& queries) {
        vector<vector<int>> df(n + 1, vector<int>(n + 1, 0));

        for (auto& q : queries) {
            int r1 = q[0], c1 = q[1], r2 = q[2], c2 = q[3];
            df[r2 + 1][c1]--;
            df[r1][c1]++;
            df[r1][c2 + 1]--;
            df[r2 + 1][c2 + 1]++;
        }

        vector<vector<int>> mat(n, vector<int>(n, 0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                int above = i ? mat[i - 1][j] : 0;
                int left = j ? mat[i][j - 1] : 0;
                int diag = (i && j) ? mat[i - 1][j - 1] : 0;

                mat[i][j] = df[i][j] + left - diag + above;
            }
        }

        return mat;
    }
};
