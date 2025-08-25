class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        int r = mat.size();
        int c = mat[0].size();
        vector<int> flatend(r * c);

        int i = 0, j = 0, k = 0;
        bool posDiag = true;
        for (int d = 0, len = r + c - 1; d < len;  d++) {
            if (posDiag) {
                while (i >= 0 && j < c) {
                    flatend[k++] = mat[i--][j++];
                }
                i++; j--;
                if (j + 1 < c) j++;
                else if (i + 1 < r) i++;
            } else {
                while (i < r && j >= 0) {
                    flatend[k++] = mat[i++][j--];
                }
                i--; j++;
                if (i + 1 < r) i++;
                else if (j + 1 < c) j++;
            }
            posDiag = !posDiag;
        }

        return flatend;
    }
};