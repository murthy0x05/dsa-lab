class Solution {
public:
    int countArrangement(int n) {
        bitset<16> visited(0);
        function<int(int)> f = [&] (int len) {
            if (len == (n + 1)) {
                return 1;
            }

            int count = 0;
            for (int i = 1; i <= n; i++) {
                if (!visited[i] && (i % len == 0 || len % i == 0)) {
                    visited.set(i);
                    count += f(len + 1);
                    visited.reset(i);
                }
            }

            return count;
        };

        return f(1);
    }
};