class Solution {
public:
    int totalXor = 0;
    vector<vector<int>> tree;
    vector<int> xorSubtree;
    vector<int> parent;

    void dfs(int u, int p, vector<int>& nums) {
        xorSubtree[u] = nums[u];
        parent[u] = p;
        for (int v : tree[u]) {
            if (v != p) {
                dfs(v, u, nums);
                xorSubtree[u] ^= xorSubtree[v];
            }
        }
    }

    int minimumScore(vector<int>& nums, vector<vector<int>>& edges) {
        int n = nums.size();
        tree.assign(n, {});
        xorSubtree.assign(n, 0);
        parent.assign(n, -1);

        // Build the tree
        for (auto& e : edges) {
            tree[e[0]].push_back(e[1]);
            tree[e[1]].push_back(e[0]);
        }

        // First DFS to compute subtree XORs
        dfs(0, -1, nums);
        totalXor = xorSubtree[0];

        int minScore = INT_MAX;
        int m = edges.size();

        // Try all pairs of edges
        for (int i = 0; i < m; ++i) {
            for (int j = i + 1; j < m; ++j) {
                int a = getChild(edges[i][0], edges[i][1]);
                int b = getChild(edges[j][0], edges[j][1]);

                int x, y, z;

                if (isAncestor(a, b)) {
                    x = xorSubtree[b];
                    y = xorSubtree[a] ^ xorSubtree[b];
                    z = totalXor ^ xorSubtree[a];
                } else if (isAncestor(b, a)) {
                    x = xorSubtree[a];
                    y = xorSubtree[b] ^ xorSubtree[a];
                    z = totalXor ^ xorSubtree[b];
                } else {
                    x = xorSubtree[a];
                    y = xorSubtree[b];
                    z = totalXor ^ x ^ y;
                }

                int mx = max({x, y, z});
                int mn = min({x, y, z});
                minScore = min(minScore, mx - mn);
            }
        }

        return minScore;
    }

    int getChild(int u, int v) {
        return parent[u] == v ? u : v;
    }

    bool isAncestor(int u, int v) {
        while (v != -1) {
            if (v == u) return true;
            v = parent[v];
        }
        return false;
    }
};
