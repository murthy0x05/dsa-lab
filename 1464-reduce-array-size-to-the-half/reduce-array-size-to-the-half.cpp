class Solution {
public:
    int minSetSize(vector<int>& arr) {
        int n = arr.size();
        vector<int> counts;
        counts.reserve(1e5 + 1);
        counts.assign(1e5 + 1, 0);
        for (int i = 0; i < n; i++) {
            counts[arr[i]]++;
        }

        sort(counts.rbegin(), counts.rend());
        int result = 0;
        for (int i = 0, removed = 0; removed < (n / 2); i++) {
            removed += counts[i];
            result++;
        }

        return result;
    }
};