class Solution {
public:
    int minScore(int n, vector<vector<int>>& roads) {
        int V = n + 1;
        vector<vector<pair<int, int>>> adj(V);
        for (const vector<int>& road: roads) {
            adj[road[0]].push_back(make_pair(road[1], road[2]));
            adj[road[1]].push_back(make_pair(road[0], road[2]));
        }

        vector<int> visited(V, false);
        function<int(int)> f = [&] (int u) {

            visited[u] = true;

            int minPos = 1e4 + 1;
            for (const auto& [v, d]: adj[u]) {
                minPos = min(minPos, d);
                if (!visited[v]) {
                    minPos = min(minPos, f(v));
                }
            }

            return minPos;
        };

        return f(1);
    }
};