struct DSU {
private:
    vector<int> parent, rank;
public:
    DSU(int n) {
        parent.resize(n);
        iota(parent.begin(), parent.end(), 0);
        rank.resize(n, 0);
    }
    int find(int i) {
        if (parent[i] == i)
            return i;
        return parent[i] = find(parent[i]);
    }
    bool unite(int i, int j) {
        int rootI = find(i);
        int rootJ = find(j);

        if (rootI == rootJ) {
            return false;
        }
        if (rank[rootI] == rank[rootJ]) {
            parent[rootI] = rootJ;
            rank[rootI]++;
        } else if (rank[rootI] < rank[rootJ]) {
            parent[rootI] = rootJ;
        } else {
            parent[rootJ] = rootI;
        }

        return true;
    }
    int sccCount() {
        int count = 0;
        for (int i = 0, len = parent.size(); i < len; i++) {
            count += parent[i] == i;
        }

        return count;
    }
};

class Solution {
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        if (n > (connections.size() + 1)) {
            return -1;
        }

        DSU dsu(n);
        for (const vector<int>& connection: connections) {
            dsu.unite(connection[0], connection[1]);
        }

        return dsu.sccCount() - 1;
    }
};