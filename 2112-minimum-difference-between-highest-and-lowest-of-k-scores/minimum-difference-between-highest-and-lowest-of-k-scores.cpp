class Solution {
public:
    int minimumDifference(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());

        int result = nums.back() - nums.front();
        for (int i = 0, n = nums.size(); i <= n - k; i++) {
            result = min(result, nums[i + k - 1] - nums[i]);
        }

        return result;
    }
};