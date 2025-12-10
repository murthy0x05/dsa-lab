class Solution {
public:
    static const int MOD = 1000000007;

    int countPermutations(vector<int>& complexity) {
        int n = complexity.size();

        for (int i = 1; i < n; i++) {
            if (complexity[i] <= complexity[0]) {
                return 0;
            }
        }

        int perms = 1;
        for (int i = 2; i <= n - 1; i++) {
            perms = (perms * 1LL * i) % MOD;
        }

        return perms;
    }
};