class Solution {
public:
    vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {
        int r = mat.size();
        int c = mat[0].size();

        int x, y;
        function<void(int, int)> sort = [&](int i, int j) {
            vector<int> freq(101, 0);
            x = i; y = j;
            while (x < r && y < c) {
                freq[mat[x++][y++]]++;
            }

            x = i; y = j;
            for (int f = 1; f <= 100; f++) {
                while (freq[f]--) mat[x++][y++] = f;
            }
        };

        for (int i = 0; i < r; i++) {
            sort(i, 0);
        }
        for (int j = 1; j < c; j++) {
            sort(0, j);
        }

        return mat;

        // 00 01 02 03 04
        // 10 11 12 13 14
        // 20 21 22 23 24
    }
};