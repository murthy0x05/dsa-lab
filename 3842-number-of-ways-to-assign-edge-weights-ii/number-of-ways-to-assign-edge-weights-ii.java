import java.util.*;

class Solution {
    int[] depth, power;
    int[][] up;
    int log;
    int MOD = 1000000007;

    void dfs(int node, int par, int d, List<List<Integer>> adj) {
        depth[node] = d;
        up[node][0] = par;

        for (int j = 1; j < log; j++) {
            if (up[node][j - 1] == -1) {
                up[node][j] = -1;
            } else {
                up[node][j] = up[up[node][j - 1]][j - 1];
            }
        }

        for (int child : adj.get(node)) {
            if (child == par) continue;
            dfs(child, node, d + 1, adj);
        }
    }

    int getLCA(int u, int v) {
        if (depth[u] < depth[v]) {
            int temp = u;
            u = v;
            v = temp;
        }

        for (int j = log - 1; j >= 0; j--) {
            if (u != -1 && depth[u] - (1 << j) >= depth[v]) {
                u = up[u][j];
            }
        }

        if (u == v) return u;

        for (int j = log - 1; j >= 0; j--) {
            if (up[u][j] != up[v][j]) {
                u = up[u][j];
                v = up[v][j];
            }
        }

        return up[u][0];
    }

    public int[] assignEdgeWeights(int[][] edges, int[][] queries) {
        int n = edges.length + 1;

        log = (int)(Math.log(n) / Math.log(2)) + 1;

        depth = new int[n + 1];
        up = new int[n + 1][log];

        for (int i = 0; i <= n; i++) {
            Arrays.fill(up[i], -1);
        }

        List<List<Integer>> adj = new ArrayList<>();
        for (int i = 0; i <= n; i++) {
            adj.add(new ArrayList<>());
        }

        for (int[] e : edges) {
            int u = e[0];
            int v = e[1];

            adj.get(u).add(v);
            adj.get(v).add(u);
        }

        dfs(1, -1, 0, adj);

        power = new int[n + 1];
        power[0] = 1;

        for (int i = 1; i <= n; i++) {
            power[i] = (int)((1L * power[i - 1] * 2) % MOD);
        }

        int[] ans = new int[queries.length];

        for (int i = 0; i < queries.length; i++) {
            int u = queries[i][0];
            int v = queries[i][1];

            if (u == v) {
                ans[i] = 0;
                continue;
            }

            int len = depth[u] + depth[v] - 2 * depth[getLCA(u, v)];
            ans[i] = power[len - 1];
        }
        return ans;
    }
}