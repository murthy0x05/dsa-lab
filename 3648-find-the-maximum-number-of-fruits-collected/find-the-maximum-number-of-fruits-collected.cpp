class Solution {
    vector<vector<int>> mem; int n;
    bool isValid(int x, int y) {
        return x >= 0 && y >= 0 && x < n && y < n;
    }
    int solve(auto& fruits, auto& dir, int x, int y, int moves) {
        if (x == n - 1 && y == n - 1 && moves == 0) {
            return 0;
        } else if (moves < 0) {
            return INT_MIN;
        } else if (dir[0].first == -1 && x <= y) {
            return INT_MIN;
        } else if (dir[0].first == 1 && x >= y) {
            return INT_MIN;
        } else {
            if (mem[x][y] != -1)
                return mem[x][y];

            int maxFruits = INT_MIN;
            for (auto& [d1, d2]: dir) {
                int nx = x + d1, ny = y + d2;
                if (isValid(nx, ny)) {
                    maxFruits = max<int>(maxFruits, solve(fruits, dir, nx, ny, moves - 1));
                }
            }

            // cout << "x:" << x << ", y:" << y << " | " << maxFruits << endl;

            if (maxFruits == INT_MIN)
                return mem[x][y] = maxFruits;
            else
                return mem[x][y] = fruits[x][y] + maxFruits;
        }
    }
public:
    int maxCollectedFruits(vector<vector<int>>& fruits) {
        n = fruits.size();
        int diagonal = 0, vertical = 0, horizontal = 0;
        mem.resize(n, vector<int>(n, -1));
        vector<pair<int, int>> dir;

        for (int i = 0; i < n; i++) {
            diagonal += fruits[i][i];
            fruits[i][i] = 0;
        }

        dir = {{-1, 1}, {0, 1}, {1, 1}};
        horizontal = solve(fruits, dir, n - 1, 0, n - 1);

        dir = {{1, -1}, {1, 0}, {1, 1}};
        vertical = solve(fruits, dir, 0, n - 1, n - 1);


        return diagonal + horizontal + vertical;
    }
};