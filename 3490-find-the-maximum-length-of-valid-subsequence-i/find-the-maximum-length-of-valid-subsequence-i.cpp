class Solution {
public:
    int maximumLength(vector<int>& nums) {
        int n = nums.size();
        int evens = 0, odds = 0;
        int odd_even = 1;
        bool odd = !(nums[0] & 1);

        for (int i = 0; i < n; i++) {
            if (nums[i] & 1) {
                odds += 1;
                if (odd) {
                    odd_even += 1;
                    odd = false;
                }
            } else {
                evens += 1;
                if (!odd) {
                    odd_even += 1;
                    odd = true;
                }
            }
        }

        return max({odds, evens, odd_even});
    }
};