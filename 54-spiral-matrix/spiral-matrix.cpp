class Solution {
    vector<int> spiral;
    int rstart, rend;
    int cstart, cend;
    void right (vector<vector<int>>& matrix) {
        if (cstart >= cend) return ;
        int r, c;
        r = rstart;
        for (c = cstart; c < cend; c++) {
            spiral.push_back(matrix[r][c]);
        }

        rstart++;
        down(matrix);
    }
    void down(auto& matrix) {
        if (rstart >= rend) return ;
        int r, c;
        c = cend - 1;
        for (r = rstart; r < rend; r++) {
            spiral.push_back(matrix[r][c]);
        }

        cend--;
        left(matrix);
    }
    void left(auto& matrix) {
        if (cstart >= cend) return ;
        int r, c;
        r = rend - 1;
        for (c = cend - 1; c >= cstart; c--) {
            spiral.push_back(matrix[r][c]);
        }

        rend--;
        up(matrix);
    }
    void up(auto& matrix) {
        if (rstart >= rend) return ;
        int r, c;
        c = cstart;
        for (r = rend - 1; r >= rstart; r--) {
            spiral.push_back(matrix[r][c]);
        }

        cstart++;
        right(matrix);
    }
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        this -> rstart = 0;
        this -> cstart = 0;
        this -> rend = matrix.size();
        this -> cend = matrix[0].size();

        right(matrix);

        return spiral;
    }
};