class Solution {
    unordered_set<int> cols, neg_diag, pos_diag;
    bool isSafe (int& row, int& col) {
        return cols.find(col) == cols.end() &&
               neg_diag.find(row - col) == neg_diag.end() && 
               pos_diag.find(row + col) == pos_diag.end();
    };
    int solve(int& n, int row) {
        if (row == n) {
            return 1;
        }

        int ans = 0;
        for (int col = 0; col < n; col++) {
            if (isSafe(row, col)) {
                cols.insert(col);
                neg_diag.insert(row - col);
                pos_diag.insert(row + col);

                ans += solve(n, row + 1);

                cols.erase(col);
                neg_diag.erase(row - col);
                pos_diag.erase(row + col);
            }
        }

        return ans;
    }
public:
    int totalNQueens(int n) {
        return solve(n, 0);
    }
};