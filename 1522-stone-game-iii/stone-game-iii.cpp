class Solution {
    int f (vector<pair<int, int>>& mem, const int& N, const vector<int>& stoneValue, int i, bool alice) {
        if (i >= N) {
            return 0;
        }

        if ((alice and mem[i].first != 1e9) or (!alice and mem[i].second != 1e9)) {
            return alice ? mem[i].first : mem[i].second;
        }
        
        int procure = alice ? INT_MIN : INT_MAX;
        int got = 0;
        for (int X = 0; X < 3 and i + X < N; X++) {
            got += stoneValue[i + X];
            if (alice) {
                procure = max(procure, got + f(mem, N, stoneValue, i + X + 1, !alice));
            } else {
                procure = min(procure, -got + f(mem, N, stoneValue, i + X + 1, !alice));
            }
        }
        
        return (alice ? mem[i].first : mem[i].second) = procure;
    }
public:
    inline string stoneGameIII(vector<int>& stoneValue) {
        const int N = stoneValue.size();

        vector<pair<int, int>> mem(N, make_pair(1e9, 1e9));

        int end = f(mem, N, stoneValue, 0, true);
        if (end == 0) {
            return "Tie";
        } else if (end > 0) {
            return "Alice";
        } else {
            return "Bob";
        }
    }
};