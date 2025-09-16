#include <numeric>

class Solution {
    using ll = long long;
    ll __lcm(ll& a, ll& b) {
        return (a * b) / gcd(a, b);
    }
public:
    vector<int> replaceNonCoprimes(vector<int>& nums) {
        int n = nums.size();

        deque<ll> dq;
        dq.push_back(nums[0]);
        for (int i = 1; i < n; i++) {
            ll x = dq.back();
            ll y = nums[i];
            if (gcd(x, y) != 1) {
                dq.pop_back();
                ll lcm = __lcm(x, y);
                while (!dq.empty()) {
                    ll ny = dq.back();
                    if (gcd(ny, lcm) != 1) {
                        dq.pop_back();
                        lcm = __lcm(ny, lcm);
                    } else {
                        break;
                    }
                }
                dq.push_back(lcm);
            } else {
                dq.push_back(y);
            }
        }

        return vector<int>(dq.begin(), dq.end());
    }
};