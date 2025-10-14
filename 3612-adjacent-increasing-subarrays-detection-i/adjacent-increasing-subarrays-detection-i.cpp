class Solution {
public:
    bool hasIncreasingSubarrays(vector<int>& nums, int k) {
        int n = nums.size();

        vector<int> inc(n); inc.back() = 1;
        for (int i = n - 2; i >= 0; i--) {
            if (nums[i] < nums[i + 1]) {
                inc[i] = inc[i + 1] + 1;
            } else {
                inc[i] = 1;
            }
        }

        for (int i = 0; i < n - 2 * k + 1; i++) {
            cout << i << endl;
            if (inc[i] >= k && inc[i + k] >= k) {
                return true;
            }
        }

        return false;
    }
};