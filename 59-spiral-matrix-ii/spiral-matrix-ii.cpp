class Solution {
    vector<vector<int>> matrix;
    int rstart, rend;
    int cstart, cend;
    void right(auto& curr) {
        if (cstart >= cend) return ;
        int r, c;
        r = rstart;
        for (c = cstart; c < cend; c++) {
            matrix[r][c] = curr;
            curr++;
        }

        rstart++;
        down(curr);
    }
    void down(auto& curr) {
        if (rstart >= rend) return ;
        int r, c;
        c = cend - 1;
        for (r = rstart; r < rend; r++) {
            matrix[r][c] = curr;
            curr++;
        }

        cend--;
        left(curr);
    }
    void left(auto& curr) {
        if (cstart >= cend) return ;
        int r, c;
        r = rend - 1;
        for (c = cend - 1; c >= cstart; c--) {
            matrix[r][c] = curr;
            curr++;
        }

        rend--;
        up(curr);
    }
    void up(auto& curr) {
        if (rstart >= rend) return ;
        int r, c;
        c = cstart;
        for (r = rend - 1; r >= rstart; r--) {
            matrix[r][c] = curr;
            curr++;
        }

        cstart++;
        right(curr);
    }
public:
    vector<vector<int>> generateMatrix(int n) {
        rstart = 0;
        cstart = 0;
        rend = n;
        cend = n;
        matrix.assign(n, vector<int>(n, 0));

        int curr = 1;
        right(curr);

        return matrix;
    }
};