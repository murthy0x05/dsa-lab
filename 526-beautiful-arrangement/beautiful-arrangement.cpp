class Solution {
public:
    int countArrangement(int n) {
        bitset<16> visited(0);
        function<int(int)> f = [&] (int len) {
            if (len == n) {
                return 1;
            }

            int count = 0;
            for (int i = 1, idx = (len + 1); i <= n; i++) {
                if (!visited[i] && (i % idx == 0 || idx % i == 0)) {
                    visited.set(i);
                    count += f(len + 1);
                    visited.flip(i);
                }
            }

            return count;
        };

        return f(0);
    }
};