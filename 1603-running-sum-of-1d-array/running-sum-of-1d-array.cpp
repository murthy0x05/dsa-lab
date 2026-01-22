class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        for (int i = 1, n = nums.size(); i < n; i++) {
            nums[i] += nums[i - 1];
        }

        return nums;
    }
};