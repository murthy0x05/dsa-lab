class Solution {
public:
    char findKthBit(int n, int k) {
        vector<int> sz(21, 0); sz[1] = 1;
        for (int i = 2; i <= 20; i++) {
            sz[i] = (sz[i - 1] * 2) + 1;
        }

        function<bool(int, int)> f = [&] (int N, int K) {
            if (N == 1) {
                return false;
            }

            int mid = sz[N] / 2;
            if (K == mid) {
                return true;
            } else if (K < mid) {
                return f(N - 1, K);
            } else {
                return !f(N - 1, 2 * mid - K);
            }
        };

        return f(n, k - 1) ? '1' : '0';
    }
};