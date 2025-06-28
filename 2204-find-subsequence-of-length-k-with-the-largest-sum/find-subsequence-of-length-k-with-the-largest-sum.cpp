class Solution {
public:
    vector<int> maxSubsequence(vector<int>& nums, int k) {
        int n = nums.size();
        vector<pair<int, int>> indexedArray(n);
        for (int i = 0; i < n; i++) {
            indexedArray[i] = make_pair(i, nums[i]);
        }

        sort(indexedArray.begin(), indexedArray.end(), [](const pair<int, int>& a, const pair<int, int>& b) {
            if (a.second != b.second) {
                return a.second > b.second;
            }
            return a.first < b.first;
        });
        sort(indexedArray.begin(), indexedArray.begin() + k, [](const pair<int, int>& a, const pair<int, int>& b) {
            return a.first < b.first;
        });

        vector<int> result(k);
        for (int i = 0; i < k; i++) {
            result[i] = indexedArray[i].second;
        }

        return result;
    }
};