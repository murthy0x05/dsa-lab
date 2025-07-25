class Solution {
public:
    int maxSum(vector<int>& nums) {
        int n = nums.size();
        unordered_set<int> seen;
        int mx = *max_element(begin(nums), end(nums));
        int result = mx; seen.insert(mx);
        for (int i = 0; i < n; i++) {
            if (!seen.count(nums[i])) {
                result = max(result, result + nums[i]);
                seen.insert(nums[i]);
            }
        }

        return result;
    }
};