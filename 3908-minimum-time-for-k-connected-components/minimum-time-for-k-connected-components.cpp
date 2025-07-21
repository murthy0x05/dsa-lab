class DSU {
    vector<int> parent, rank;
public:
    DSU(int _capacity) {
        parent.resize(_capacity);
        rank.resize(_capacity, 0);
        for (int i = 0; i < _capacity; i++) {
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

        if (rank[i_root] < rank[j_root])
            parent[i_root] = j_root;
        else if (rank[i_root] > rank[j_root])
            parent[j_root] = i_root;
        else {
            parent[j_root] = i_root;
            rank[i_root]++;
        }

        return true;
    }
    int no_of_components() {
        int count = 0;
        for (int i = 0, n = parent.size(); i < n; i++) {
            count += parent[i] == i;
        }

        return count;
    }
};

bool isValid(vector<vector<int>>& edges, int& k, int& n, int t) {
    int components = n, e = edges.size();
    DSU dsu(n); int i = e - 1;

    while (i >= 0 && edges[i][2] > t) {
        if (dsu.unite(edges[i][0], edges[i][1])) {
            components--;
        }
        i--;
    }

    return components >= k; 
}

class Solution {
public:
    int minTime(int n, vector<vector<int>>& edges, int k) {
        if (!edges.size()) return 0;
        auto cmp = [](auto& a, auto& b) {
            return a[2] < b[2];
        };
        sort(edges.begin(), edges.end(), cmp);
        
        int low = 0, high = edges.back()[2], result = 0;
        while (low <= high) {
            int mid = low + ((high - low) >> 1);
            if (isValid(edges, k, n, mid)) {
                cout << "I am here..." << endl;
                result = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        return result;
    }
};