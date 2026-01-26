class Solution {
    using ll = long long;
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n = nums.size();
        if (n < 4) return {};

        vector<vector<int>> result;
        sort(nums.begin(), nums.end());
        for (int a = 0; a < n - 3; a++) {
            if (a > 0 && nums[a] == nums[a - 1]) continue;
            for (int b = a + 1; b < n - 2; b++) {
                if ((b - a) > 1 && nums[b] == nums[b - 1]) continue;
                int c = b + 1, d = n - 1;
                while (c < d) {
                    ll sum = 0LL + nums[a] + nums[b] + nums[c] + nums[d];
                    if (sum == target) {
                        result.push_back({nums[a], nums[b], nums[c], nums[d]});
                        c++; d--;
                        while (c < d && nums[c] == nums[c - 1]) c++;
                        while (c < d && nums[d] == nums[d + 1]) d--;
                    } else if (sum < target) {
                        c++;
                    } else {
                        d--;
                    }
                }
            }
        }

        return result;
    }
};