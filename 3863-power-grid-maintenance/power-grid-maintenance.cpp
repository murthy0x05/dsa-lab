class DSU {
    vector<int> parent, rank;
    vector<set<int>> online_nodes;
public:
    vector<bool> operational;
    DSU(int _capacity) {
        parent.resize(_capacity + 1);
        rank.resize(_capacity + 1, 0);
        online_nodes.resize(_capacity + 1);
        operational.resize(_capacity + 1, true);
        for (int i = 0; i < _capacity + 1; i++) {
            parent[i] = i;
            online_nodes[i].insert(i);
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

        int x, y;
        if (rank[i_root] < rank[j_root]) {
            parent[i_root] = j_root;
            x = j_root;
            y = i_root;
        } else if (rank[i_root] > rank[j_root]) {
            parent[j_root] = i_root;
            x = i_root;
            y = j_root;
        } else {
            parent[j_root] = i_root;
            rank[i_root]++;
            x = i_root;
            y = j_root;
        }

        for (int node: online_nodes[y]) {
            online_nodes[x].insert(node);
        }
        online_nodes[y].clear();

        return true;
    }

    int resolve(int i) {
        if (operational[i]) return i;
        else {
            int i_root = find(i);
            for (int node: online_nodes[i_root]) {
                if (operational[node]) {
                    return node;
                } else {
                    online_nodes[i_root].erase(node);
                }
            }
            return -1;
        }
    }
};

class Solution {
    #define psb push_back
public:
    vector<int> processQueries(int c, vector<vector<int>>& connections, vector<vector<int>>& queries) {
        DSU dsu(c);
        for (auto& connection: connections) {
            dsu.unite(connection[0], connection[1]);
        }

        vector<int> result;
        for (auto& query: queries) {
            if (1 == query[0])
                result.psb(dsu.resolve(query[1]));
            else {
                dsu.operational[query[1]] = false;
            }
        }

        return result;
    }
};