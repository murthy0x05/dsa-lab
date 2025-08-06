class NumArray {
    vector<int> tree;
    int n, size;
public:
    void build(vector<int>& arr, int node, int start, int end) {
        if (start == end) {
            tree[node] = arr[start];
        } else {
            int mid = start + ((end - start) >> 1);
            build(arr, 2 * node + 1, start, mid);
            build(arr, 2 * node + 2, mid + 1, end);
            tree[node] = tree[2 * node + 1] + tree[2 * node + 2];
        }
    }
    NumArray(vector<int>& arr) {
        this -> n = arr.size();
        int height = ceil(log2(n));
        this -> size = 2 * pow(2, height) - 1;
        tree.resize(size);
        build(arr, 0, 0, n - 1);
    }
    int query(int node, int start, int end, int& l, int& r) {
        if (start > r || end < l) {
            return 0;
        } else if (start >= l && end <= r) {
            return tree[node];
        } else {
            int mid = start + ((end - start) >> 1);
            return query(2 * node + 1, start, mid, l, r) 
                 + query(2 * node + 2, mid + 1, end, l, r);
        }
    }
    void update(int node, int start, int end, int& idx, int& value) {
        if (start == end) {
            tree[node] = value;
        } else {
            int mid = start + ((end - start) >> 1);
            if (idx <= mid) {
                update(2 * node + 1, start, mid, idx, value);
            } else {
                update(2 * node + 2, mid + 1, end, idx, value);
            }
            tree[node] = tree[2 * node + 1] + tree[2 * node + 2];
        }
    }
    void update(int index, int val) {
        update(0, 0, n - 1, index, val);
    }
    
    int sumRange(int left, int right) {
        return query(0, 0, n - 1, left, right);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */