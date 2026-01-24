class Solution {
    using ll = long long;
public:
    int minPairSum(vector<int>& nums) {
        int n = nums.size();

        sort(nums.begin(), nums.end());
        long long result = 2LL * nums.front();
        for (int l = 0, r = n - 1; l < r; l++, r--) {
            result = max<ll>(result, nums[l] + nums[r]);
        }

        return result;
    }
};