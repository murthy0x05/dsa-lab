class Solution {
public:
    int minimumHammingDistance(vector<int>& source, vector<int>& target, vector<vector<int>>& allowedSwaps) {
        const int V = source.size();
        int hamming = 0;
        vector<vector<int>> adj(V);
        vector<bool> visited(V, false);

        for (const vector<int>& allowedSwap: allowedSwaps) {
            adj[allowedSwap[0]].push_back(allowedSwap[1]);
            adj[allowedSwap[1]].push_back(allowedSwap[0]);
        }

        function<void(unordered_map<int, int>&, unordered_map<int, int>&, const int&)> dfs = [&] (unordered_map<int, int>& need, unordered_map<int, int>& have, const int& curr) {
            visited[curr] = true;
            need[target[curr]] += 1;
            have[source[curr]] += 1;
            for (const int& nbr: adj[curr]) {
                if (!visited[nbr]) {
                    dfs(need, have, nbr);
                }
            }
        };
        for (int i = 0; i < V; i++) {
            if (!visited[i]) {
                unordered_map<int, int> need, have;
                dfs(need, have, i);

                for (const auto& [val, occ]: need) {
                    hamming += min(occ, have[val]);
                }
            }
        }

        return V - hamming;
    }
};