class Solution {
    vector<int> tree;
    int n, size;
    void build(vector<int>& arr, int node, int start, int end) {
        if (start == end) {
            tree[node] = arr[start];
        } else {
            int mid = start + ((end - start) >> 1);
            build(arr, 2 * node + 1, start, mid);
            build(arr, 2 * node + 2, mid + 1, end);
            tree[node] = max<int>(tree[2 * node + 1], tree[2 * node + 2]);
        }
    }
    bool placeFruit(int node, int start, int end, int fruit) {
        if (start == end) {
            if (tree[node] >= fruit) {
                tree[node] = -1;
                return true;
            } else {
                return false;
            }
        } else {
            bool placed = false;
            int mid = start + ((end - start) >> 1);
            if (tree[2 * node + 1] >= fruit) {
                placed = placeFruit(2 * node + 1, start, mid, fruit);
            } else if (tree[2 * node + 2] >= fruit) {
                placed = placeFruit(2 * node + 2, mid + 1, end, fruit);
            }
            if (placed) {
                tree[node] = max<int>(tree[2 * node + 1], tree[2 * node + 2]);
                return true;
            } else {
                return false;
            }
        }
    }
public:
    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
        this -> n = baskets.size();
        int height = ceil(log2(n));
        this -> size = 2 * pow(2, height) - 1;
        tree.resize(size, 0);
        int unplaced = 0;
        build(baskets, 0, 0, n - 1);

        for (int i = 0; i < n; i++) {
            if (!placeFruit(0, 0, n - 1, fruits[i])) {
                unplaced++;
            }
        }

        return unplaced;
    }
};