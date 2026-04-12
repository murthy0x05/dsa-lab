class Solution {
    struct f {
        int x, y;
        f (int _x = -1, int _y = -1) : x(_x), y(_y) {}
    };
    struct box {
        int cost;
        f f1, f2;
        box (int _c) : cost(_c) {}
    };
public:
    int minimumDistance(string word) {
        const int N = word.size();

        vector<vector<vector<int>>> mem(N, vector<vector<int>>(27, vector<int>(27, -1)));
        function<int(int, int, int)> solve = [&] (int i, int f1, int f2) {
            if (i == N) {
                return 0;
            }
            if (mem[i][f1 + 1][f2 + 1] != -1) {
                return mem[i][f1 + 1][f2 + 1];
            }
            
            int f1_x = f1 / 6, f1_y = f1 % 6;
            int f2_x = f2 / 6, f2_y = f2 % 6;
            int x = (word[i] - 'A') / 6, y = (word[i] - 'A') % 6;
            int cost1 = -1;
            if (f1 < 0) {
                cost1 = solve(i + 1, word[i] - 'A', f2);
            } else {
                cost1 = abs(x - f1_x) + abs(y - f1_y) + solve(i + 1, word[i] - 'A', f2);
            }

            int cost2 = -1;
            if (f2 < 0) {
                cost2 = solve(i + 1, f1, word[i] - 'A');
            } else {
                cost2 = abs(x - f2_x) + abs(y - f2_y) + solve(i + 1, f1, word[i] - 'A');
            }

            return mem[i][f1 + 1][f2 + 1] = min(cost1, cost2);
        };

        return solve(0, -1, -1);
    }
};