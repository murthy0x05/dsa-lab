class Solution {
    unordered_set<int> cols, pos_diag, neg_diag;
    void backtrack(auto& states, auto& state, int& n, int row) {
        if (row == n) {
            states.push_back(state);
            return ;
        }

        for (int col = 0; col < n; col++) {
            if (0 == cols.count(col) &&
                0 == neg_diag.count(row - col) &&
                0 == pos_diag.count(row + col)) {
    
                cols.insert(col);
                neg_diag.insert(row - col);
                pos_diag.insert(row + col);
                state[row][col] = 'Q';
                
                backtrack(states, state, n, row + 1);

                cols.erase(col);
                neg_diag.erase(row - col);
                pos_diag.erase(row + col);
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