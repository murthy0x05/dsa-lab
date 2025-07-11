class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> subsets;

        for (int i = 0; i < (1 << n); i++) {
            subsets.push_back({});
            for (int j = 0; j < n; j++) {
                if (i & (1 << j)) {
                    subsets.back().push_back(nums[j]);
                }
            }
        }

        return subsets;
    }
};