class Solution {
public:
    bool canCross(vector<int>& stones) {
        int n = stones.size();

        unordered_map<int, unordered_map<int, bool>> mem(n);
        unordered_map<int, int> ids;
        for (int i = 0; i < n; i++) {
            ids[stones[i]] = i;
        }
        function<bool(int, int)> dfs = [&](int k, int i) {
            if (i == (n - 1)) {
                return true;
            } else {
                if (mem.count(i) && mem[i].count(k)) {
                    return mem[i][k];
                }

                bool canReach = false;
                if (ids.count(stones[i] + k)) {
                    canReach = canReach || dfs(k, ids[stones[i] + k]);
                }
                if (k - 1 > 0 && ids.count(stones[i] + k - 1)) {
                    canReach = canReach || dfs(k - 1, ids[stones[i] + k - 1]);
                }
                if (ids.count(stones[i] + k + 1)) {
                    canReach = canReach || dfs(k + 1, ids[stones[i] + k + 1]);
                }

                return mem[i][k] = canReach;
            }
        };

        // for (int i = 0; i < n; i++) {
        //     cout << mem[i] << ' ';
        // }
        // cout << endl;

        if (stones[1] != 1) {
            return false;
        }
        return dfs(1, 1);
    }
};