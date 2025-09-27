class Solution {
    // vector<int> nums;
    // vector<ll> factorial;
    // void solve(string& ans, int k) {
    //     if (k <= 0) {
    //         return ;
    //     }

    //     int n = nums.size();
    //     int curr = k / factorial[n - 1];
    //     ans.push_back(nums[curr - 1] + '0');
    //     nums.erase(nums.begin() + (curr - 1));
    //     k -= curr * factorial[n - 1];
    //     solve(ans, k);
    // }
    using ll = long long;
public:
    string getPermutation(int n, int k) {
        set<int> seen;
        for (int i = 1; i <= n; i++) {
            seen.insert(i);
        }
        vector<ll> f(10, 1);
        for (int i = 2; i < 10; i++) {
            f[i] = i * f[i - 1];
        }

        string result("");
        ll kth = k - 1;
        while (!seen.empty()) {
            ll curr = kth / f[n - 1];
            auto it = next(seen.begin(), curr);
            result.push_back('0' + *it);
            seen.erase(it);

            kth = kth - f[n - 1] * (kth / f[n - 1]);
            n--;
        }

        return result;
    }
};