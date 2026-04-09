class Solution {
    static const long long MOD = 1000000007LL;
    long long mod_pow(long long a, long long e) {
        long long r = 1 % MOD;
        a %= MOD;
        while (e > 0) {
            if (e & 1) r = (r * a) % MOD;
            a = (a * a) % MOD;
            e >>= 1;
        }
        return r;
    }
    long long modinv(long long a) { return mod_pow((a % MOD + MOD) % MOD, MOD - 2); }
    
    struct Query {
        int l, r, k;
        long long v;
    };
public:
    int xorAfterQueries(vector<int>& a, vector<vector<int>>& qs) {
        int n = a.size();
        vector<long long> mult(n, 1);

        int B = max(1, (int)std::sqrt(n));
        vector<vector<vector<int>>> small(B + 1);
    
        for (auto &qq : qs) {
            if (qq[2] <= B) small[qq[2]].push_back(qq);
            else {
                for (int idx = qq[0]; idx <= qq[1]; idx += qq[2])
                    mult[idx] = (mult[idx] * qq[3]) % MOD;
            }
        }
    
        for (int k = 1; k <= B; ++k) {
            if (small[k].empty()) continue;
    
            vector<vector<int>> bucket(k);
            for (int r = 0; r < k; ++r)
                for (int i = r; i < n; i += k) bucket[r].push_back(i);
    
            vector<vector<long long>> diff(k);
            for (int r = 0; r < k; ++r)
                diff[r].assign(bucket[r].size() + 1, 1LL);
    
            for (auto &qq : small[k]) {
                int r = (qq[0] % k + k) % k;
                auto &vec = bucket[r];
                if (vec.empty()) continue;
    
                auto itL = lower_bound(vec.begin(), vec.end(), qq[0]);
                auto itR = upper_bound(vec.begin(), vec.end(), qq[1]);
                if (itL >= itR) continue;
    
                int L = int(itL - vec.begin());
                int R = int(itR - vec.begin()) - 1;
    
                diff[r][L]      = (diff[r][L] * qq[3]) % MOD;
                diff[r][R + 1]  = (diff[r][R + 1] * modinv(qq[3])) % MOD;
            }
    
            for (int r = 0; r < k; ++r) {
                long long cur = 1;
                for (size_t t = 0; t + 1 < diff[r].size(); ++t) {
                    cur = (cur * diff[r][t]) % MOD;
                    int idx = bucket[r][t];
                    mult[idx] = (mult[idx] * cur) % MOD;
                }
            }
        }
    
        long long ans = 0;
        for (int i = 0; i < n; ++i) {
            long long val = (a[i] % MOD) * mult[i] % MOD;
            ans ^= val;
        }
    
        return ans;
    }
};

// class Solution {

//     const int MOD = 1e9 + 7;
    
//     long long power(long long base, long long exp) {
//         long long res = 1;
//         base %= MOD;
//         while (exp > 0) {
//             if (exp % 2 == 1) res = (res * base) % MOD;
//             base = (base * base) % MOD;
//             exp /= 2;
//         }
//         return res;
//     }
    
//     long long modInverse(long long n) {
//         return power(n, MOD - 2);
//     }
    
//     int solve(int n, std::vector<int>& nums, int q, std::vector<std::vector<int>>& queries) {
//         std::vector<std::vector<std::vector<int>>> grouped_queries(n + 1);
//         for (const auto& query : queries) {
//             int l = query[0];
//             int k = query[2];
//             grouped_queries[k].push_back(query);
//         }
    
//         for (int k = 1; k <= n; ++k) {
//             if (grouped_queries[k].empty()) continue;
            
//             std::unordered_map<int, std::vector<std::pair<int, int>>> updates_by_remainder;
//             for (const auto& query : grouped_queries[k]) {
//                 int l = query[0];
//                 int r = query[1];
//                 int v = query[3];
//                 int remainder = l % k;
//                 updates_by_remainder[remainder].push_back({r, v});
//             }
            
//             for (auto const& [remainder, updates] : updates_by_remainder) {
//                 std::vector<long long> diff_array((n + k) / k + 1, 1);
                
//                 for (const auto& p : updates) {
//                     int r = p.first;
//                     int v = p.second;
//                     int start_idx = (remainder) / k;
//                     int end_idx = r / k;
                    
//                     diff_array[start_idx] = (diff_array[start_idx] * v) % MOD;
//                     if (end_idx + 1 < diff_array.size()) {
//                         diff_array[end_idx + 1] = (diff_array[end_idx + 1] * modInverse(v)) % MOD;
//                     }
//                 }
                
//                 long long current_product = 1;
//                 for (int i = 0; i < diff_array.size(); ++i) {
//                     current_product = (current_product * diff_array[i]) % MOD;
//                     int original_idx = remainder + i * k;
//                     if (original_idx < n) {
//                         nums[original_idx] = (nums[original_idx] * current_product) % MOD;
//                     }
//                 }
//             }
//         }
    
//         long long xor_sum = 0;
//         for (long long val : nums) {
//             xor_sum ^= val;
//         }
    
//         return xor_sum;
//     }
//     int xorAfterQueries(vector<int>& a, vector<vector<int>>& qs) {
//         return solve(a.size(), a, qs.size(), qs);
//     }
// };