class RangeFreqQuery {
    unordered_map<int, vector<int>> occ;
    int ub(int& value, int& target) {
        int low = 0, high = occ[value].size() - 1;
        while (low <= high) {
            int mid = low + ((high - low) >> 1);
            if (occ[value][mid] > target) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        return low;
    }
    int lb(int& value, int& target) {
        int low = 0, high = occ[value].size() - 1;
        while (low <= high) {
            int mid = low + ((high - low) >> 1);
            if (occ[value][mid] < target) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }

        return low;
    }
public:
    RangeFreqQuery(vector<int>& arr) {
        for (int i = 0, n = arr.size(); i < n; i++) {
            occ[arr[i]].push_back(i);
        }
    }
    
    int query(int left, int right, int value) {
        int u = ub(value, right);
        int l = lb(value, left);

        return u - l;
    }
};

/**
 * Your RangeFreqQuery object will be instantiated and called as such:
 * RangeFreqQuery* obj = new RangeFreqQuery(arr);
 * int param_1 = obj->query(left,right,value);
 */