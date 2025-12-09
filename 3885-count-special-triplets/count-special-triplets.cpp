class Solution {
    const int MOD = 1e9 + 7;
    using ll = long long;
public:
    int specialTriplets(vector<int>& nums) {
        int n = nums.size();

        unordered_map<int, int> left;
        left[nums[0]] += 1;

        unordered_map<int, int> right;
        for (int i = 1; i < n; i++) {
            right[nums[i]] += 1;
        }

        ll result = 0;
        for (int i = 1; i < n; i++) {
            right[nums[i]]--;
            result = result + 1LL * left[nums[i] * 2] * right[nums[i] * 2];
            left[nums[i]]++;
        }

        return result % MOD;
    }
};