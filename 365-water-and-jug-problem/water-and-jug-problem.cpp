class Solution {
public:
    bool canMeasureWater(int x, int y, int target) {
        vector<vector<bool>> seen(x + 1, vector<bool>(y + 1, false));

        function<bool(int, int)> dfs = [&](int X, int Y) {
            if (X < 0 || y < 0 || X > x || Y > y) {
                return false;
            }
            if (seen[X][Y]) {
                return false;
            }
            if (X + Y == target) {
                return true;
            }

            seen[X][Y] = true;

            return dfs(min(x, X + Y), max(0, Y - (x - X))) ||
                   dfs(max(0, X - (y - Y)), min(y, X + Y)) ||
                   dfs(0, Y) ||
                   dfs(X, 0) ||
                   dfs(X, y) ||
                   dfs(x, Y);
        };

        return dfs(x, 0) || dfs(0, y);
    }
};