class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int max_ele = *max_element(nums.begin(), nums.end());
        int n = nums.size(), max_len = 1;
        int count = 1;
        for (int i = 1; i < n; i++) {
            if (nums[i] == nums[i - 1] && nums[i] == max_ele) count++;
            else count = 1;
            max_len = max(max_len, count);
        }

        return max_len;
    }
};