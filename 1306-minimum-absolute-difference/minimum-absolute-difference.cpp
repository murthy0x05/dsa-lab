class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        int n = arr.size();
        sort(arr.begin(), arr.end());

        int abs_diff = arr.back() - arr.front() + 1;
        vector<vector<int>> result;
        int len = 0;
        for (int i = 1; i < n; i++) {
            if (arr[i] - arr[i - 1] == abs_diff) {
                if (result.size() <= len) {
                    result.push_back({arr[i - 1], arr[i]});
                } else {
                    result[len] = {arr[i - 1], arr[i]};
                }
                len++;
            } else if (arr[i] - arr[i - 1] < abs_diff) {
                abs_diff = arr[i] - arr[i - 1];
                len = 0;
                if (result.size() <= len) {
                    result.push_back({arr[i - 1], arr[i]});
                } else {
                    result[len] = {arr[i - 1], arr[i]};
                }
                len++;
            }
        }

        result.resize(len);
        return result;
    }
};