class Solution {
    using ll = long long;
public:
    bool makesquare(vector<int>& matchsticks) {
        int n = matchsticks.size();

        sort(matchsticks.rbegin(), matchsticks.rend());
        ll total = accumulate(matchsticks.begin(), matchsticks.end(), 0LL);
        if (total & 3) {
            return false;
        }
        
        ll need = total >> 2;
        vector<int> sides(4, 0);
        function<bool(int)> dfs = [&](int id) {
            if (id == n) {
                return sides[0] == need &&
                       sides[1] == need &&
                       sides[2] == need &&
                       sides[3] == need;
            }

            for (int i = 0; i < 4; i++) {
                if (sides[i] + matchsticks[id] > need) {
                    continue;
                }

                sides[i] += matchsticks[id];
                if (dfs(id + 1)) return true;
                sides[i] -= matchsticks[id];

                // if (sides[i] == 0) break; 
            }

            return false;
        };

        return dfs(0);
    }
};