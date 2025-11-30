class Solution {
    using ll = long long;
public:
    int minSubarray(vector<int>& nums, int p) {
        int n = nums.size();

        ll total = accumulate(nums.begin(), nums.end(), 0LL);
        int excess = total % p;
        if (!excess) {
            return 0;
        }

        int csum = 0;
        unordered_map<int, int> cache;
        cache[0] = -1;

        int result = n;
        for (int i = 0; i < n; i++) {
            csum = (csum + nums[i]) % p;
            if (cache.count((csum - excess + p) % p)) {
                result = min(result, i - cache[(csum - excess + p) % p]);
            }
            cache[csum] = i;
        }

        if (result == n) return -1;
        else return result;
    }
};