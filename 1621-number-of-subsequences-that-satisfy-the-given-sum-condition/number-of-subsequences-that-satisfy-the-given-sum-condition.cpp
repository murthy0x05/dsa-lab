class Solution {
    const int MOD = 1e9 + 7;
    vector<int> preComputeTwoPower(int n) {
        vector<int> twoPower(n);
        twoPower[0] = 1;
        for (int i = 1; i < n; i++) {
            twoPower[i] = (twoPower[i - 1] * 2LL) % MOD;
        }
        return twoPower;
    }
public:
    int numSubseq(vector<int>& nums, int target) {
        int n = nums.size(), result = 0;
        sort(nums.begin(), nums.end());

        vector<int> twoPower = preComputeTwoPower(n);
        int start = 0, end = n - 1;
        while (start <= end) {
            if (nums[start] + nums[end] > target) {
                end -= 1;
            } else {
                result = (result + twoPower[end - start]) % MOD;
                start += 1;
            }
        }

        return result;
    }
};