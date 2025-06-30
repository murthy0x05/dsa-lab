class Solution {
public:
    int findLHS(vector<int>& nums) {
        int n = nums.size();
        int start = 0, end = 0, longest = 0;
        std::sort(nums.begin(), nums.end());

        while (end < n) {
            while (end < n && nums[end] - nums[start] <= 1) {
                end++;
            }
            if (nums[end - 1] - nums[start] == 1) {
                longest = std::max(longest, end - start);
            }
            start++;
        }

        return longest;
    }
};