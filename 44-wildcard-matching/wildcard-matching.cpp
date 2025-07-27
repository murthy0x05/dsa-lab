class Solution {
    vector<vector<int>> mem;
    bool solve(int i, int j, string& s, string &p) {
        if (i < 0 && j < 0) 
            return true;
        if (j < 0)
            return false;
        if (i < 0) {
            for (int k = 0; k <= j; k++) {
                if (p[k] != '*') {
                    return false;
                }
            }
            return true;
        }
        if (mem[i][j] != -1)
            return mem[i][j];
        
        if (p[j] == '*') {
            return mem[i][j] = solve(i, j - 1, s, p) || solve(i - 1, j, s, p);
        } else if (s[i] == p[j] || p[j] == '?') {
            return mem[i][j] = solve(i - 1, j - 1, s, p);
        } else {
            return mem[i][j] = false;
        }
    }
public:
    bool isMatch(string s, string p) {
        int n = s.size(), m = p.size();
        mem.assign(n, vector<int>(m, -1));

        return solve(n - 1, m - 1, s, p);
    }
};