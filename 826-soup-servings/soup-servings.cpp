class Solution {
    vector<vector<double>> mem;
    double solve(int a, int b) {
        if (a <= 0 && b <= 0)
            return 0.5;
        if (a <= 0)
            return 1.0;
        if (b <= 0)
            return 0.0;

        if (mem[a][b] != -1)
            return mem[a][b];
        
        return mem[a][b] = 0.25 * (solve(a - 4, b) + solve(a - 3, b - 1)
                                 + solve(a - 2, b - 2) + solve(a - 1, b - 3)); 
    }
public:
    double soupServings(int n) {
        if (n >= 5000) return 1.0;
        int m = (int) std::ceil(n / 25.0);
        mem.resize(m + 1, vector<double>(m + 1, -1));

        return solve(m, m);
    }
};