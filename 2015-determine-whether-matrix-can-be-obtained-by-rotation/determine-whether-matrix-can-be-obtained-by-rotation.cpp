class Solution {
public:
    bool findRotation(vector<vector<int>>& mat, vector<vector<int>>& target) {
        const int R = mat.size(), C = mat[0].size();

        bool r1 = true, r2 = true, r3 = true, r4 = true;
        for (int i = 0; i < R && r1; i++) {
            for (int j = 0; j < C; j++) {
                if (mat[i][j] != target[i][j]) {
                    r1 = false;
                    break;
                }
            }
        }
        if (r1) return r1;

        for (int i = 0; i < R && r2; i++) {
            for (int j = 0; j < C; j++) {
                if (mat[C - j - 1][i] != target[i][j]) {
                    r2 = false;
                    break;
                }
            }
        }
        if (r2) return r2;

        for (int i = 0; i < R && r3; i++) {
            for (int j = 0; j < C; j++) {
                if (mat[R - i - 1][C - j - 1] != target[i][j]) {
                    r3 = false;
                    break;
                }
            }
        }
        if (r3) return r3;

        for (int i = 0; i < R && r4; i++) {
            for (int j = 0; j < C; j++) {
                if (mat[j][R - i - 1] != target[i][j]) {
                    r4 = false;
                    break;
                }
            }
        }

        if (r4) return r4;
        else return false;
    }
};