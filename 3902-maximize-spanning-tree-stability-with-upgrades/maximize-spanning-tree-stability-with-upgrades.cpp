struct DSU {
    int N;
    vector<int> parent,
                rank;
    DSU (int _N) : N(_N) {
        parent.resize(N);
        iota(parent.begin(), parent.end(), 0);
        rank.resize(N, 0);
    }

    bool unite(int i, int j) {
        int iRoot = find(i),
            jRoot = find(j);
        if (iRoot == jRoot) {
            return false;
        }

        if (rank[iRoot] == rank[jRoot]) {
            parent[jRoot] = iRoot;
            rank[iRoot] += 1;
        } else if (rank[iRoot] < rank[jRoot]) {
            parent[iRoot] = jRoot;
        } else {
            parent[jRoot] = iRoot;
        }

        return true;
    }
    int find(int i) {
        if (parent[i] == i) {
            return i;
        }
        return parent[i] = find(parent[i]);
    }
    void reset() {
        for (int i = 0; i < N; i++) {
            parent[i] = i;
            rank[i] = 0;
        }
    }
};

class Solution {
public:
    int maxStability(int n, vector<vector<int>>& edges, int k) {
        const int V = n,
                  E = edges.size();

        DSU dsu(V);
        sort(edges.begin(), edges.end(), [&](const vector<int>& a, const vector<int>& b) {
            return a[2] > b[2];
        });
        long long low = 0, high = 1e10 + 1;
        for (int i = 0; i < E; i++) {
            if (edges[i][3]) {
                if (!dsu.unite(edges[i][0], edges[i][1])) {
                    return -1;
                } else {
                    high = min<long long>(high, edges[i][2]);
                }
            }
        }

        function<bool(const long long&, int)> feasible = [&] (const long long& strength, int K) {
            dsu.reset();
            for (int i = 0; i < E; i++) {
                if (edges[i][3]) {
                    dsu.unite(edges[i][0], edges[i][1]);
                }
            }

            for (int i = 0; i < E; i++) {
                if (!edges[i][3]) {
                    if (edges[i][2] < strength) {
                        if (dsu.unite(edges[i][0], edges[i][1])) {
                            if (K <= 0 || ((2 * edges[i][2]) < strength)) {
                                return false;
                            }
                            K -= 1;
                        }
                    } else {
                        dsu.unite(edges[i][0], edges[i][1]);
                    }
                }
            }

            int comps = 0;
            for (int i = 0; i < V; i++) {
                comps += (dsu.parent[i] == i);
            }

            if (comps != 1) {
                return false;
            }

            return true;
        };

        while (low <= high) {
            long long mid = low + ((high - low) >> 1);
            if (feasible(mid, k)) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        
        return high == 0 ? -1 : high;
    }
};