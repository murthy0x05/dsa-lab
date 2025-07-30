class Solution {
    int rows, cols;
    vector<int> dir = {-1, 0, 1, 0, -1};
    bool isValid(int x, int y) {
        return x >= 0 && y >= 0 && x < rows && y < cols;
    }
    bool search(auto& board, auto& word, int& n, int idx, int x, int y) {
        if (idx == n) {
            return true;
        }

        int found = false;
        for (int i = 0; i < 4; i++) {
            int nx = x + dir[i];
            int ny = y + dir[i + 1];
            if (isValid(nx, ny) && board[nx][ny] == word[idx]) {
                board[nx][ny] = '#';
                if (search(board, word, n, idx + 1, nx, ny)) {
                    return true;
                }
                board[nx][ny] = word[idx];
            }
        }

        return false;
    }
public:
    bool exist(vector<vector<char>>& board, string word) {
        this -> rows = board.size();
        this -> cols = board[0].size();
        int n = word.size();

        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (board[i][j] == word[0]) {
                    board[i][j] = '#';
                    if (search(board, word, n, 1, i, j)) {
                        // cout << i << " " << j << endl;
                        return true;
                    }
                    board[i][j] = word[0];
                }
            }
        }

        return false;
    }
};