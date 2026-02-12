class Solution {
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        const int N = days.size();

        vector<int> mem(N, -1);
        function<int(int, int)> f = [&](int di, int validTill) {
            if (di == N) {
                return 0;
            }
            if (days[di] <= validTill) {
                return f(di + 1, validTill);
            }
            if (mem[di] != -1)
                return mem[di];

            return mem[di] = min({
                costs[0] + f(di + 1, days[di]),
                costs[1] + f(di + 1, days[di] + 6),
                costs[2] + f(di + 1, days[di] + 29)
            });
        };

        return f(0, 0);
    }
};