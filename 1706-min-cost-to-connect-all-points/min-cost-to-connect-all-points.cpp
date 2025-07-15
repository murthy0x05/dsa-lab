#include <tuple>

class DSU {
    vector<int> parent;
    vector<int> rank;
public:
    DSU (int c) {
        parent.resize(c);
        rank.assign(c, 0);
        for (int i = 0; i < c; i++) {
            parent[i] = i;
        }
    }
    int find(int i) {
        if (parent[i] != i) 
            parent[i] = find(parent[i]);
        return parent[i];
    }
    bool unite(int i, int j) {
        int i_root = find(i);
        int j_root = find(j);
        if (i_root == j_root)
            return false;

        if (rank[i_root] < rank[j_root]) {
            parent[i_root] = j_root;
        } else if (rank[i_root] > rank[j_root]) {
            parent[j_root] = i_root;
        } else {
            parent[i_root] = j_root;
            rank[j_root]++;
        }

        return true;
    }
};

class Solution {
    typedef tuple<int, int, int> State;
    inline int cost(auto& a, auto& b) {
        return abs(a[0] - b[0]) + abs(a[1] - b[1]);
    }
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();
        DSU dsu(n);
        vector<State> weights;
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                weights.push_back(make_tuple(cost(points[i], points[j]), i, j));
            }
        }

        sort(weights.begin(), weights.end(), [](State& a, State& b) {
            return get<0>(a) < get<0>(b);
        });
        int result = 0;
        for (State& state: weights) {
            if (dsu.unite(get<1>(state), get<2>(state))) {
                result += get<0>(state);
                // cout << get<1>(state) << " " << get<2>(state) << " " << result << endl;
            }
        }

        return result;
    }
};