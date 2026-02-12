class Solution {
public:
    bool isMatch(string s, string p) {
        int n = s.size(),
            m = p.size();

        vector<vector<char>> mem(n, vector<char>(m, '!'));
        function<bool(int, int)> f = [&] (int n, int m) {
            if (m < 0) {
                return n < 0;
            } else if (n < 0) {
                while (m >= 0) {
                    if (p[m] != '*') {
                        return false;
                    }
                    m -= 2;
                }

                return true;
            } else {
                if (mem[n][m] != '!')
                    return mem[n][m] == 'y';

                bool matched = false;
                if (p[m] == '.' || s[n] == p[m]) {
                    matched = f(n - 1, m - 1);
                } else if (p[m] == '*') {
                    matched = f(n, m - 2);
                    if (!matched && (s[n] == p[m - 1] || p[m - 1] == '.')) {
                        matched = matched || f(n - 1, m);
                    }
                }

                mem[n][m] = matched ? 'y' : 'n';
                return matched;
            }
        }; 

        return f(n - 1, m - 1);
    }
};