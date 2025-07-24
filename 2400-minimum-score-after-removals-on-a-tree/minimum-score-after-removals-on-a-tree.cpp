class Solution {
public:
    // Helper function to compute the score from three component XORs
    int calc(int a, int b, int c) {
        return max({a, b, c}) - min({a, b, c});
    }

    int minimumScore(vector<int>& nums, vector<vector<int>>& edges) {
        int n = nums.size(), time = 0;
        vector<int> sum(n), in(n), out(n);
        vector<vector<int>> adj(n);

        // Build tree
        for (auto& e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        // DFS to compute subtree XORs and Euler tour times
        function<void(int, int)> dfs = [&](int node, int parent) {
            in[node] = time++;
            sum[node] = nums[node];
            for (int child : adj[node]) {
                if (child == parent) continue;
                dfs(child, node);
                sum[node] ^= sum[child];
            }
            out[node] = time;
        };

        dfs(0, -1); // root the tree at node 0

        int result = INT_MAX;

        // Try removing every pair of non-root edges (nodes u and v)
        for (int u = 1; u < n; ++u) {
            for (int v = u + 1; v < n; ++v) {
                // Case 1: v is in subtree of u
                if (in[v] > in[u] && in[v] < out[u]) {
                    int part1 = sum[0] ^ sum[u];
                    int part2 = sum[u] ^ sum[v];
                    int part3 = sum[v];
                    result = min(result, calc(part1, part2, part3));
                }
                // Case 2: u is in subtree of v
                else if (in[u] > in[v] && in[u] < out[v]) {
                    int part1 = sum[0] ^ sum[v];
                    int part2 = sum[v] ^ sum[u];
                    int part3 = sum[u];
                    result = min(result, calc(part1, part2, part3));
                }
                // Case 3: u and v are in disjoint subtrees
                else {
                    int part1 = sum[0] ^ sum[u] ^ sum[v];
                    int part2 = sum[u];
                    int part3 = sum[v];
                    result = min(result, calc(part1, part2, part3));
                }
            }
        }

        return result;
    }
};
