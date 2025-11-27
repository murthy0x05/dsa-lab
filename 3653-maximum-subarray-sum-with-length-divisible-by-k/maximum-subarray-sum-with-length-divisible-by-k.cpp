class Solution {
    using ll = long long;
public:
    long long maxSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();

        vector<ll> prefix(k, 1e15);
        prefix[0] = 0;

        ll result = LLONG_MIN;
        ll sum = 0;
        for (int i = 0; i < n; i++) {
            sum += nums[i];
            result = max(result, sum - prefix[(i + 1) % k]);
            prefix[(i + 1) % k] = min<ll>(prefix[(i + 1) % k], sum);
        }

        return result;
    }
};