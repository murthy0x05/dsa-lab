class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int n = nums.size();
        if (n < 2) return n;

        int si = 1, sd = 1;
        int longest = 1;

        for (int i = 1; i < n; i++) {
            if (nums[i-1] < nums[i]) {
                si++;
                sd = 1;
            } else if (nums[i-1] > nums[i]) {
                sd++;
                si = 1;
            } else {
                si = 1;
                sd = 1;
            }
            longest = max(longest, max(si, sd));
        }

        return longest;
    }
};