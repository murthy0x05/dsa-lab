class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        const int N = costs.size();

        vector<int> occ(1e5 + 1, 0);
        for (int i = 0; i < N; i++) {
            occ[costs[i]]++;
        }

        int result = 0;
        for (int i = 1; coins >= i && i <= (1e5); i++) {
            result += min(occ[i], (int)(coins / i));
            coins -= min(occ[i], (int)(coins / i)) * i;
        }

        return result;
    }
};