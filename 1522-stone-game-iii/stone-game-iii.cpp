class Solution {
public:
    string stoneGameIII(vector<int>& stoneValue) {
        const int N = stoneValue.size();

        vector<vector<int>> mem(N, vector<int>(2, 1e9));
        auto f = [&] (auto&& f, int i, bool alice) {
            if (i >= N) {
                return 0;
            }

            if (mem[i][alice] != 1e9) {
                return mem[i][alice];
            } 

            int procure = alice ? INT_MIN : INT_MAX;
            int got = 0;
            for (int X = 0; X < 3 and i + X < N; X++) {
                got += stoneValue[i + X];
                if (alice) {
                    procure = max(procure, got + f(f, i + X + 1, !alice));
                } else {
                    procure = min(procure, -got + f(f, i + X + 1, !alice));
                }
            }

            return mem[i][alice] = procure;
        };

        int end = f(f, 0, true);
        if (end == 0) {
            return "Tie";
        } else if (end > 0) {
            return "Alice";
        } else {
            return "Bob";
        }
    }
};