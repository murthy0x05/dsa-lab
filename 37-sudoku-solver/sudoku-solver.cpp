class Solution {
    vector<int> r, c, b;
    bool solved;
    bool isSafe(int i, int j, int pos) {
        if (!(r[i] & (1 << pos)) && !(c[j] & (1 << pos))) {
            int box = (i / 3) * 3 + (j / 3);
            return !(b[box] & (1 << pos));
        }

        return false;
    }
    void place(int i, int j, int pos) {
        r[i] = r[i] | (1 << pos);
        c[j] = c[j] | (1 << pos);
        int box = (i / 3) * 3 + (j / 3);
        b[box] = b[box] | (1 << pos);
    }
    void unplace(int i, int j, int pos) {
        r[i] = r[i] ^ (1 << pos);
        c[j] = c[j] ^ (1 << pos);
        int box = (i / 3) * 3 + (j / 3);
        b[box] = b[box] ^ (1 << pos);
    }
    void backtrack(auto& board, int i, int j) {
        if (i >= 9) {
            solved = true;
            return ;
        }
        if (j >= 9) {
            backtrack(board, i + 1, 0);
            return ;
        }
        if (board[i][j] == '.') {
            for (int num = 0; num < 9; num++) {
                if (isSafe(i, j, num)) {
                    board[i][j] = '1' + num;
                    place(i, j, num);

                    backtrack(board, i, j + 1);

                    if (solved) return ;
                    else {
                        board[i][j] = '.';
                        unplace(i, j, num);
                    }
                }
            }
        } else {
            // remember, if a number is found, go to next cell
            backtrack(board, i, j + 1);
        }
    }
public:
    void solveSudoku(vector<vector<char>>& board) {
        r.resize(9, 0); // rows
        c.resize(9, 0); // cols
        b.resize(9, 0); // boxes
        solved = false;

        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                if (board[i][j] != '.') {
                    int pos = board[i][j] - '1';
                    r[i] = r[i] | (1 << pos);
                    c[j] = c[j] | (1 << pos);
                    int box = (i / 3) * 3 + (j / 3);
                    b[box] = b[box] | (1 << pos);
                }
            }
        }

        cout << (isSafe(2, 0, 8) ? "safe" : "not safe") << endl;

        backtrack(board, 0, 0);
    }
};