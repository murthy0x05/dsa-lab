class Solution {
    bool isSafe(auto& state, int& row, int& col, int& n) {
        // column check
        for (int i = 0; i < row; i++)
            if (state[i][col] == 'Q')
                return false;

        // negative diagonal check
        for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--)
            if (state[i][j] == 'Q')
                return false;

        // positive diagonal check
        for (int i = row - 1, j = col + 1; i >= 0 && j < n; i--, j++)
            if (state[i][j] == 'Q')
                return false;
        
        return true;
    }
    void backtrack(auto& states, auto& state, int& n, int row) {
        if (row == n) {
            states.push_back(state);
            return ;
        }

        for (int col = 0; col < n; col++) {
            if (isSafe(state, row, col, n)) {
                state[row][col] = 'Q';
                backtrack(states, state, n, row + 1);
                state[row][col] = '.';
            }
        }
    }
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> states;
        vector<string> state(n, string(n, '.'));

        backtrack(states, state, n, 0);
        
        return states;
    }
};