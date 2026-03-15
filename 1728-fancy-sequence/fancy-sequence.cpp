class Fancy {
    const int MOD = 1e9 + 7;
    const int MAX_N = 100005;

    struct Node {
        long long val = 0;
        long long mult = 1; 
        long long add = 0; 
    };

    vector<Node> tree;
    int sz;

    inline int left(int n) { return 2 * n + 1; }
    inline int right(int n) { return 2 * n + 2; }

    void applyTransformation(int node, long long m, long long a) {
        tree[node].val = (tree[node].val * m + a) % MOD;
        tree[node].mult = (tree[node].mult * m) % MOD;
        tree[node].add = (tree[node].add * m + a) % MOD;
    }

    void push(int node) {
        if (tree[node].mult != 1 || tree[node].add != 0) {
            applyTransformation(left(node), tree[node].mult, tree[node].add);
            applyTransformation(right(node), tree[node].mult, tree[node].add);
            
            tree[node].mult = 1;
            tree[node].add = 0;
        }
    }

    void append(int node, int l, int r, int id, int val) {
        if (l == r) {
            tree[node].val = val;
            tree[node].mult = 1;
            tree[node].add = 0;
            return;
        }
        push(node);
        int mid = l + ((r - l) >> 1);
        if (id <= mid) {
            append(left(node), l, mid, id, val);
        } else {
            append(right(node), mid + 1, r, id, val);
        }
    }

    void updateRange(int node, int l, int r, int ql, int qr, long long m, long long a) {
        if (r < ql || l > qr) return;
        
        if (l >= ql && r <= qr) {
            applyTransformation(node, m, a);
            return;
        }

        push(node);
        int mid = l + ((r - l) >> 1);
        updateRange(left(node), l, mid, ql, qr, m, a);
        updateRange(right(node), mid + 1, r, ql, qr, m, a);
    }

    int query(int node, int l, int r, int id) {
        if (l == r) {
            return tree[node].val;
        }
        push(node);
        int mid = l + ((r - l) >> 1);
        if (id <= mid) {
            return query(left(node), l, mid, id);
        } else {
            return query(right(node), mid + 1, r, id);
        }
    }

public:
    Fancy() {
        sz = 0;
        tree.resize(4 * MAX_N);
    }

    void append(int val) {
        append(0, 0, MAX_N - 1, sz, val);
        sz++;
    }

    void addAll(int inc) {
        if (sz > 0) {
            updateRange(0, 0, MAX_N - 1, 0, sz - 1, 1, inc);
        }
    }

    void multAll(int m) {
        if (sz > 0) {
            updateRange(0, 0, MAX_N - 1, 0, sz - 1, m, 0);
        }
    }

    int getIndex(int idx) {
        if (idx >= sz) return -1;
        return query(0, 0, MAX_N - 1, idx);
    }
};