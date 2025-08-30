class Solution {
    #define pii pair<int, int>
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int n = board.size();
        unordered_map<int, set<char>> rows;
        unordered_map<int, set<char>> cols;
        map<pii, set<char>> cube;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                char num = board[i][j];
                if (num != '.') {
                    bool inRow = rows[i].find(num) != rows[i].end();
                    bool inCol = cols[j].find(num) != cols[j].end();
                    auto& currCube = cube[make_pair(i / 3, j / 3)];
                    bool inCube = currCube.find(num) != currCube.end();

                    if (inRow || inCol || inCube) {
                        return false;
                    } else {
                        rows[i].insert(num);
                        cols[j].insert(num);
                        currCube.insert(num);
                    }
                }
            };
        };
        
        return true;
    }

    // bool isValidSudoku {
        // int n = board.size();
        // vector<unordered_set<char>> rows(n);
        // vector<unordered_set<char>> cols(n);
        // vector<unordered_set<char>> cube(n);

        // for (int i = 0; i < n; i++) {
        //     for (int j = 0; j < n; j++) {
        //         if (board[i][j] == '.') continue;
        //         int c = (i / 3) * 3 + (j / 3);
        //         if (rows[i].find(board[i][j]) != rows[i].end() || cols[j].find(board[i][j]) != cols[j].end() || cube[c].find(board[i][j]) != cube[c].end()) {
        //             return false;
        //         } else {
        //             rows[i].insert(board[i][j]);
        //             cols[j].insert(board[i][j]);
        //             cube[c].insert(board[i][j]);
        //         }
        //     }
        // }

        // return true;
    // }
};