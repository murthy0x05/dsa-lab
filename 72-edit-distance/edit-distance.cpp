class Solution {
    string s1, s2;
    vector<vector<int>> mem;
    int solve(int i, int j) {
        if (i == -1)
            return j + 1;
        if (j == -1)
            return i + 1;
        if (mem[i][j] != -1)
            return mem[i][j];

        if (s1[i] == s2[j]){
            return mem[i][j] = solve(i - 1, j - 1);
        } else {
            return mem[i][j] = 1 + min({
                solve(i - 1, j),
                solve(i, j - 1),
                solve(i - 1, j - 1)
            });
        }
    }
public:
    int minDistance(string word1, string word2) {
        this -> s1 = word1;
        this -> s2 = word2;
        int n = s1.size(), m = s2.size();
        mem.assign(n, vector<int>(m, -1));
        solve(n - 1, m - 1);
        if (n == 0) {
            return m;
        } else if (m == 0) {
            return n;
        } else {
            return mem[n - 1][m - 1];
        }
    }
};