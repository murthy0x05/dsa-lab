struct SegTree {
private:
    int N;
    struct Node {
        int mn, mx, lazy;
        Node (int _mn, int _mx, int _lazy) : mn(_mn), mx(_mx), lazy(_lazy) {}
        Node () : mn(INT_MAX), mx(INT_MIN), lazy(0) {}
    };
    vector<Node> tree;
    inline int left (int node) { return 2 * node + 1; }
    inline int right (int node) { return 2 * node + 2; }
    inline void pull (int node) {
        tree[node].mn = min(tree[left(node)].mn, tree[right(node)].mn);
        tree[node].mx = max(tree[left(node)].mx, tree[right(node)].mx);
    }
    void push(int node) {
        if (tree[node].lazy) {
            int l = left(node), r = right(node);
                if (l >= tree.size()) return;

            tree[left(node)].mn += tree[node].lazy;
            tree[left(node)].mx += tree[node].lazy;

            tree[right(node)].mn += tree[node].lazy;
            tree[right(node)].mx += tree[node].lazy;

            tree[left(node)].lazy += tree[node].lazy;
            tree[right(node)].lazy += tree[node].lazy;

            tree[node].lazy = 0;
        }
    }
    void build(const vector<int>& arr, int node, int l, int r) {
        if (l == r) {
            tree[node].mn = tree[node].mx = arr[l];
            return ;
        }

        int mid = l + ((r - l) >> 1);
        build(arr, left(node), l, mid);
        build(arr, right(node), mid + 1, r);

        tree[node].mn = min(tree[left(node)].mn, tree[right(node)].mn);
        tree[node].mx = max(tree[left(node)].mx, tree[right(node)].mx);
    }
    void rangeUpdate(int node, int l, int r, int diff, int rl, int rr) {
        if (l > rr || r < rl) {
            return ;
        }
        if (l >= rl && r <= rr) {
            tree[node].mn += diff;
            tree[node].mx += diff;
            tree[node].lazy += diff;
            return ;
        }

        push(node);

        int mid = l + ((r - l) >> 1);
        rangeUpdate(left(node), l, mid, diff, rl, rr);
        rangeUpdate(right(node), mid + 1, r, diff, rl, rr);

        pull(node);
    }
    int findRightMostZero(int node, int l, int r) {
        if (tree[node].mn > 0 || tree[node].mx < 0) {
            return -1;
        }
        if (l == r) return l;

        push(node);

        int mid = l + ((r - l) >> 1);
        int result = findRightMostZero(right(node), mid + 1, r);
        if (result != -1) {
            return result;
        }

        return findRightMostZero(left(node), l, mid);
    }
public:
    SegTree(const vector<int>& arr) {
        this -> N = arr.size();
        int ht = (31 - __builtin_clz(N)) + ((N & -N) != N);
        tree.resize((1 << (ht + 1)) - 1);
        build(arr, 0, 0, N - 1);
    }
    void rangeUpdate(int diff, int rl, int rr) {
        rangeUpdate(0, 0, N - 1, diff, rl, rr);
    }
    int findRightMostZero() {
        return findRightMostZero(0, 0, N - 1);
    }
};

class Solution {
public:
    int longestBalanced(vector<int>& nums) {
        const int N = nums.size();

        map<int, int> occ = {{nums[N - 1], N - 1}};
        vector<int> nextOcc(N, N);
        for (int i = N - 2; i >= 0; i--) {
            if (occ.count(nums[i])) {
                nextOcc[i] = occ[nums[i]];
            }
            occ[nums[i]] = i;
        }

        vector<int> ps(N); ps[0] = (nums[0] & 1) ? -1 : 1;
        set<int> seen = {nums[0]};
        for (int i = 1; i < N; i++) {
            if (!seen.count(nums[i])) {
                ps[i] = ((nums[i] & 1) ? -1 : 1);
                seen.insert(nums[i]);
            }
            ps[i] += ps[i - 1];
        }

        SegTree segTree(ps);
        int result = segTree.findRightMostZero() + 1;
        for (int i = 1; i < N; i++) {
            int nextPos = nextOcc[i - 1];
            segTree.rangeUpdate(((nums[i - 1] & 1) ? 1 : -1), i, nextPos - 1);

            result = max(result, segTree.findRightMostZero() - i + 1);
        }

        return result;
    }
};