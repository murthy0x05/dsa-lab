class Solution {
    int lb(vector<int>& arr, int target) {
        int low = 0, high = arr.size() - 1;
        while (low <= high) {
            int mid = low + ((high - low) >> 1);
            if (arr[mid] < target) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }

        return low;
    }
    int ub(vector<int>& arr, int target) {
        int low = 0, high = arr.size() - 1;
        while (low <= high) {
            int mid = low + ((high - low) >> 1);
            if (arr[mid] > target) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        return low;
    }
public:
    int intersectionSizeTwo(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), [](const vector<int>& a, const vector<int>& b) {
            if (a[1] != b[1]) {
                return a[1] < b[1];
            } else {
                return a[0] > b[0];
            }
        });

        vector<int> arr = {intervals[0][1] - 1, intervals[0][1]};
        for (int i = 1, len = intervals.size(); i < len; i++) {
            int e = lb(arr, intervals[i][1]);
            int s = lb(arr, intervals[i][0]);
            if (s == arr.size()) {
                arr.push_back(intervals[i][1] - 1);
                arr.push_back(intervals[i][1]);
            } else if (e == arr.size()) {
                if (e - s == 1) {
                    arr.push_back(intervals[i][1]);
                }
            }
        }

        // for (int& a: arr) {
        //     cout << a << ' ';
        // }
        // cout << endl;

        return arr.size();
    }
};