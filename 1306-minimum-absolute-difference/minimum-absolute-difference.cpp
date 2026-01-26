class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        int n = arr.size();
        sort(arr.begin(), arr.end());

        int abs_diff = arr.back() - arr.front() + 1;
        vector<vector<int>> result;
        for (int i = 1; i < n; i++) {
            if (arr[i] - arr[i - 1] > abs_diff) {
                continue;
            } else if (arr[i] - arr[i - 1] < abs_diff) {
                abs_diff = arr[i] - arr[i - 1];
                result.clear();
            }
            result.push_back({arr[i - 1], arr[i]});
        }

        return result;
    }
};