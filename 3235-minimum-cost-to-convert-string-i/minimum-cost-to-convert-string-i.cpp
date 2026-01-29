class Solution {
    using ll = long long;
public:
    long long minimumCost(string source, string target, vector<char>& original, vector<char>& changed, vector<int>& cost) {
        const ll INF = 2e9 + 1;

        vector<vector<ll>> minCost(26, vector<ll>(26, INF));
        for (int i = 0, len = original.size(); i < len; i++) {
            int id1 = original[i] - 'a',
                id2 = changed[i] - 'a';
            minCost[id1][id2] = min<ll>(minCost[id1][id2], cost[i]);
        }
        for (int k = 0; k < 26; k++) {
            for (int i = 0; i < 26; i++) {
                for (int j = 0; j < 26; j++) {
                    minCost[i][j] = min<ll>(minCost[i][j], minCost[i][k] + minCost[k][j]);
                }
            }
        }
        
        long long total = 0LL;
        for (int i = 0, len = source.size(); i < len; i++) {
            int id1 = source[i] - 'a',
                id2 = target[i] - 'a';
            if (id1 != id2) {
                if (minCost[id1][id2] == INF)
                    return -1;
                total += minCost[id1][id2];
            }
        }

        return total;
    }
};