class Solution {
public:
    int numTrees(int n) {
        vector<vector<int>> mem(n + 1, vector<int>(n + 1, -1));
        function<int(int, int)> f = [&] (int low, int high) {
            if (low >= high) {
                return 1;
            }
            if (mem[low][high] != -1)
                return mem[low][high];

            int ways = 0;
            for (int i = low; i <= high; i++) {
                ways += f(low, i - 1) * f(i + 1, high);
            }
            
            return mem[low][high] = ways;
        };

        return f(1, n);
    }
};