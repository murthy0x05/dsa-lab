class Solution {
public:
    int maxSum(vector<int>& nums, int k) {
        const int N = nums.size();
        const int MOD = 1e9 + 7;

        vector<int> bc(32, 0);
        for (const int& num: nums) {
            int x = num;
            for (int i = 0; i < 32; i++) {
                if (x) {
                    bc[i] += x & 1;
                    x = x >> 1;
                } else {
                    break;
                }
            }
        }

        // for (int i = 0; i < 32; i++) {
        //     cout << bc[i] << ' ';
        // }
        // cout << endl;

        int result = 0;
        while (k--) {
            int val = 0;
            for (int i = 0; i < 32; i++) {
                if (bc[i]) {
                    val += 1 << i;
                    bc[i]--;
                }
            }

            result = (result + 0LL + 1LL * val * val) % MOD;
        }

        return result;
    }
};