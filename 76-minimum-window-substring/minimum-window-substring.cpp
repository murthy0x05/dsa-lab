class Solution {
public:
    string minWindow(string s, string t) {
        const int M = s.size(),
                  N = t.size();

        map<char, int> occ;
        for (int i = 0; i < N; i++) {
            occ[t[i]] += 1;
        }

        int li = -1, ri = M + 1;
        for (int l = 0, r = 0, covered = 0; r < M; r++) {
            if (occ.count(s[r])) {
                if (occ[s[r]] > 0) {
                    covered++;
                }
                occ[s[r]] -= 1;
            }

            if (r == M - 1) {
                cout << covered << endl;
            }
            while (covered == N) {
                if ((ri - li + 1) > (r - l + 1)) {
                    ri = r; li = l;
                }
                if (occ.count(s[l])) {
                    occ[s[l]] += 1;
                    if (occ[s[l]] > 0)
                        covered--;
                }
                l++;
            }
        }

        if (li == -1)
            return "";
        return s.substr(li, ri - li + 1);
    }
};