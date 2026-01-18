class Solution {
public:
    int largestMagicSquare(vector<vector<int>>& grid) {
        int r = grid.size(), c = grid[0].size();

        vector<vector<int>> row(r+1, vector<int>(c+1));
        vector<vector<int>> col(r+1, vector<int>(c+1));
        vector<vector<int>> dia(r+1, vector<int>(c+2));     
        vector<vector<int>> anti(r+1, vector<int>(c+2));

        for (int i = 1; i <= r; i++) {
            for (int j = 1; j <= c; j++) {
                int v = grid[i-1][j-1];
                row[i][j] = row[i][j-1] + v;
                col[i][j] = col[i-1][j] + v;
                dia[i][j] = dia[i-1][j-1] + v;
            }
            for (int j = c; j >= 1; j--) {
                anti[i][j] = anti[i-1][j+1] + grid[i-1][j-1];
            }
        }

        auto isMagic = [&](int side) {
            for (int i = 0; i + side <= r; i++) {
                for (int j = 0; j + side <= c; j++) {
                    int d1 = dia[i+side][j+side] - dia[i][j];
                    int d2 = anti[i+side][j+1] - anti[i][j+side+1];

                    if (d1 != d2) continue; 

                    bool ok = true;
                    for (int k = 0; k < side && ok; k++) {
                        int rs = row[i+k+1][j+side] - row[i+k+1][j];
                        int cs = col[i+side][j+k+1] - col[i][j+k+1];
                        if (rs != d1 || cs != d1) {
                            ok = false;
                            break;
                        }
                    }
                    if (ok) return true;
                }
            }
            return false;
        };

        for (int side = min(r, c); side >= 2; side--) {
            if (isMagic(side)) return side;
        }
        return 1;
    }
};
