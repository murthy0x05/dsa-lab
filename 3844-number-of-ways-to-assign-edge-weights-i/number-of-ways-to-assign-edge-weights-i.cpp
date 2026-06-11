class Solution {
    static constexpr long long MOD = 1e9 + 7;

    long long modPow(long long a, long long b) {
        long long res = 1;
        while (b) {
            if (b & 1) res = (res * a) % MOD;
            a = (a * a) % MOD;
            b >>= 1;
        }
        return res;
    }

public:
    int assignEdgeWeights(vector<vector<int>>& edges) {
        int n = edges.size() + 1;

        vector<vector<int>> adj(n + 1);
        for (auto &e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        int maxDepth = 0;

        function<void(int,int,int)> dfs = [&](int u, int p, int depth) {
            maxDepth = max(maxDepth, depth);

            for (int v : adj[u]) {
                if (v != p) {
                    dfs(v, u, depth + 1);
                }
            }
        };

        dfs(1, 0, 0);

        if (maxDepth == 0) return 0;

        return (int)modPow(2, maxDepth - 1);
    }
};