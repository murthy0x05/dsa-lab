class Solution {
public:
    inline int maxOperations(const string& s) {
        int n = s.size();

        int ops = 0, po = s[0] - '0';
        for (int i = 1; i < n; i++) {
            if (s[i] == '1') {
                if (s[i] != s[i - 1]) {
                    ops += po;
                }
                po++;
            }
        }

        return (s[n - 1] - '0') ? ops : ops + po;
    }
};