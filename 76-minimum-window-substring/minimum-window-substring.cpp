class Solution {
public:
    string minWindow(string s, string t) {
        const int M = s.size();
        const int N = t.size();

        unordered_map<int, int> occ;
        for (int i = 0; i < N; i++) {
            occ[t[i]]++;
        }

        int smallest = INT_MAX;
        int rl = -1, rr = -1;
        int incomp = occ.size();
        int l = 0, r = 0;
        while (l < M) {
            if (incomp == 0) {
                if (smallest > (r - l)) {
                    smallest = r - l;
                    rl = l;
                    rr = r;
                }
                if (occ.count(s[l])) {
                    occ[s[l]]++;
                    if (occ[s[l]] == 1) {
                        incomp++;
                    }
                }
                l++;
            } else {
                if (r == M) break;
                if (occ.count(s[r])) {
                    occ[s[r]]--;
                    if (occ[s[r]] == 0) {
                        incomp--;
                    }
                }
                r++;
            }
        }

        if (smallest == INT_MAX) {
            return "";
        }
        return s.substr(rl, rr - rl);
    }
};