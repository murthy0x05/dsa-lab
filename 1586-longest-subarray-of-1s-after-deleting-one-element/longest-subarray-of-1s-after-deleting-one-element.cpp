class Solution {
    vector<int> mem; int n;
    int solve(auto& nums, int i) {
        if (mem[i] != -1) return mem[i];

        if (nums[i] == 0) {
            return mem[i] = 0;
        } else {
            return mem[i] = nums[i] + solve(nums, i + 1);
        }
    }
public:
    int longestSubarray(vector<int>& nums) {
        int n = nums.size();
        if (1 == n) return 0;
        else if (2 == n) return max<int>(nums[0], nums[1]);
        vector<int> left(n), right(n);

        left[0] = nums[0];
        for (int i = 1; i < n; i++) {
            if (1 == nums[i])
                left[i] = 1 + left[i - 1];
            else
                left[i] = 0;
        }

        right[n - 1] = nums[n - 1];
        for (int i = n - 2; i >= 0; i--) {
            if (1 == nums[i])
                right[i] = 1 + right[i + 1];
            else
                right[i] = 0;
        }

        int maxlen = 0;
        if (nums[0] == 0) 
            maxlen = max<int>(maxlen, right[1]);
        if (nums[n - 1] == 0)
            maxlen = max<int>(maxlen, left[n - 2]);
        for (int i = 1; i < n - 1; i++) {
            maxlen = max<int>(maxlen, left[i - 1] + right[i + 1]);
        }

        return maxlen;
    }
};