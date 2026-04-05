class Solution {
    using ll = long long;
public:
    long long minIncrease(vector<int>& nums) {
        const int N = nums.size();

        if (N & 1) {
            ll result = 0LL;
            for (int i = 1; i < N - 1; i+=2)
                result += max<ll>({nums[i - 1] - nums[i] + 1, nums[i + 1] - nums[i] + 1, 0LL});
            
            return result;
        } else {
            ll result1 = 0LL, result2 = 0LL, result3 = LLONG_MAX;
            vector<ll> ps1(N + 1),
                       ps2(N + 1);
            for (int i = 1; i < N - 1; i+=2) {
                ps1[i + 1] = max<ll>({nums[i - 1] - nums[i] + 1, nums[i + 1] - nums[i] + 1, 0LL});
                result1 += max<ll>({nums[i - 1] - nums[i] + 1, nums[i + 1] - nums[i] + 1, 0LL});
            }
            for (int i = 2; i < N - 1; i+=2) {
                ps2[i + 1] = max<ll>({nums[i - 1] - nums[i] + 1, nums[i + 1] - nums[i] + 1, 0LL});
                result2 += max<ll>({nums[i - 1] - nums[i] + 1, nums[i + 1] - nums[i] + 1, 0LL});
            }
            for (int i = 0; i < N; i++) {
                ps1[i + 1] += ps1[i];
                ps2[i + 1] += ps2[i];
            }
            for (int i = 0; i < N - 1; i+=2) {
                result3 = min(result3, ps1[i] + (ps2[N] - ps2[i + 1]));
            }

            return min<ll>({result1, result2, result3});
        }
    }
};