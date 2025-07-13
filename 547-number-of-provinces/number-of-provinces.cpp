class DSU {
    vector<int> parent, rank;
public:
    DSU(int capacity) {
        parent.resize(capacity);
        rank.resize(capacity, 0);
        for (int i = 0; i < capacity; i++)
            parent[i] = i;
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
    
        if (rank[i_root] < rank[j_root])
            parent[i_root] = j_root;
        else if (rank[i_root] > rank[j_root])
            parent[j_root] = i_root;
        else {
            parent[i_root] = j_root;
            rank[j_root]++;
        }
        cout << i << " " << j << endl;

        return true;
    }
};

class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        DSU dsu(n); int result = n;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (i != j && (1 == isConnected[i][j]) && dsu.unite(i, j)) {
                    result--;
                }
            }
        }

        return result;
    }
};