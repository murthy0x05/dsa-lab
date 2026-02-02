class SegmentTree {
    int n, size;
    vector<int> tree;
    inline int left(int node) { return 2 * node + 1; }
    inline int right(int node) { return 2 * node + 2; }
    void build(vector<int>& arr, int node, int l, int r) {
        if (l == r) {
            if (l >= 1 && r <= n - 2) {
                tree[node] = (arr[l] > arr[l - 1]) && (arr[r] > arr[r + 1]);
            }
        } else {
            int mid = l + ((r - l) >> 1);
            build(arr, left(node), l, mid);
            build(arr, right(node), mid + 1, r);
            tree[node] = tree[left(node)] + tree[right(node)];
        }
    }
    void update(int node, int l, int r, int id, int val) {
        if (l == r) {
            tree[node] = val;
        } else {
            int mid = l + ((r - l) >> 1);
            if (id >= l && id <= mid) {
                update(left(node), l, mid, id, val);
            } else {
                update(right(node), mid + 1, r, id, val);
            }

            tree[node] = tree[left(node)] + tree[right(node)];
        }
    }
    int query(int node, int l, int r, int qs, int qe) {
        if (l > qe || r < qs) {
            return 0;
        }
        if (l >= qs && r <= qe) {
            return tree[node];
        }

        int mid = l + ((r - l) >> 1);
        return query(left(node), l, mid, qs, qe) +
               query(right(node), mid + 1, r, qs, qe);
    }
public:
    SegmentTree (vector<int>& arr) {
        n = arr.size();
        int h = ceil(log2(n));
        size = 2 * (1 << h) - 1;
        tree.resize(size, 0);
        build(arr, 0, 0, n - 1);
    }
    void update(int id, int val) {
        update(0, 0, n - 1, id, val);
    }
    int query(int qs, int qe) {
        return query(0, 0, n - 1, qs, qe);
    }
};
class Solution {
public:
    vector<int> countOfPeaks(vector<int>& nums, vector<vector<int>>& queries) {
        const int n = nums.size(),
                  q = queries.size();
        vector<int> result;

        SegmentTree segTree(nums);
        for (const vector<int>& query: queries) {
            if (query[0] == 1) {
                result.push_back(segTree.query(query[1] + 1, query[2] - 1));
            } else {
                int id = query[1], val = query[2];
                nums[id] = val;
                if (id >= 2 && id < n-2) {
                    segTree.update(id - 1, ((nums[id - 1] > nums[id - 2]) && (nums[id - 1] > nums[id])) ?1:0);
                    segTree.update(id, ((nums[id] > nums[id - 1]) && (nums[id] > nums[id + 1])) ?1:0);
                    segTree.update(id + 1, ((nums[id + 1] > nums[id]) && (nums[id + 1] > nums[id + 2])) ?1:0);
                } else if (id == 1) {
                    segTree.update(id, ((nums[id] > nums[id - 1]) && (nums[id] > nums[id + 1])) ?1:0);
                    if (id != n - 2) {
                        segTree.update(id + 1, ((nums[id + 1] > nums[id]) && (nums[id + 1] > nums[id + 2])) ?1:0);
                    } 
                } else if (id == 0) {
                    segTree.update(id + 1, ((nums[id + 1] > nums[id]) && (nums[id + 1] > nums[id + 2])) ?1:0);
                } else if (id == n - 2) {
                    // cout << "Here" << endl;
                    // cout << ((nums[id - 1] > nums[id - 2]) && (nums[id - 1] > nums[id])) << endl;
                    segTree.update(id, ((nums[id] > nums[id - 1]) && (nums[id] > nums[id + 1])) ?1:0);
                    if (id != 1) {
                        segTree.update(id - 1, ((nums[id - 1] > nums[id - 2]) && (nums[id - 1] > nums[id])) ?1:0);
                    }
                } else {
                    segTree.update(id - 1, ((nums[id - 1] > nums[id - 2]) && (nums[id - 1] > nums[id])) ?1:0);
                }
            }
        }

        return result;
    }
};