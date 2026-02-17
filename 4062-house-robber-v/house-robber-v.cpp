class Solution {
    using ll = long long;
public:
    long long rob(vector<int>& nums, vector<int>& colors) {
        const int N = nums.size();
        if (N == 1) {
            return nums[0];
        }
        if (N == 2) {
            return (colors[1] - colors[0]) ? (nums[0] + nums[1]) : max(nums[0], nums[1]);
        }

        ll h2 = nums[0],
           h1 = (colors[1] - colors[0]) ? (nums[0] + nums[1]) : max(nums[0], nums[1]),
           h0;
        for (int i = 2; i < N; i++) {
            if (colors[i] - colors[i - 1]) {
                h0 = h1 + nums[i];
            } else {
                h0 = max(h1, h2 + nums[i]);
            }
            h2 = h1; h1 = h0;
        }

        return h0;
    }
};