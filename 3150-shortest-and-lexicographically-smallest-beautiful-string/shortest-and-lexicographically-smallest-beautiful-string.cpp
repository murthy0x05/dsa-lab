class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        const int N = s.size();

        int L = 0, R = N + 1;
        for (int l = 0, r = 0, O = 0; l <= r; ) {
            while (r < N and O < k) {
                O += s[r] == '1';
                r++;
            }
            if (O < k) break;

            if (r - l < R - L) {
                L = l; R = r;
            } else if (r - l == R - L) {
                if (s.substr(l, r - l) < s.substr(L, R - L)) {
                    L = l; R = r;
                }
            }

            O -= s[l] == '1';
            l++;
        }

        return R == (N + 1) ? "" : s.substr(L, R - L);
    }
};