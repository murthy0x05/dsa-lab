class Solution {
    int n, m;
    vector<vector<int>> grid_;
    vector<vector<bool>> visited;
    unordered_map<int, vector<tuple<int, int, vector<int>>>> directions;

    bool dfs(int i, int j) {
        visited[i][j] = true;
        if (i == n - 1 && j == m - 1) return true;
        for (auto& [di, dj, reachable] : directions[grid_[i][j]]) {
            int nextI = i + di;
            int nextJ = j + dj;
            if (nextI >= 0 && nextI < n &&
                nextJ >= 0 && nextJ < m &&
                !visited[nextI][nextJ] &&
                find(reachable.begin(), reachable.end(), grid_[nextI][nextJ]) != reachable.end() &&
                dfs(nextI, nextJ)) {
                return true;
            }
        }
        return false;
    }

public:
    bool hasValidPath(vector<vector<int>>& grid) {
        directions = {
            {1, {{0, -1, {1, 4, 6}}, {0, 1, {1, 3, 5}}}},
            {2, {{-1, 0, {2, 3, 4}}, {1, 0, {2, 5, 6}}}},
            {3, {{0, -1, {1, 4, 6}}, {1, 0, {2, 5, 6}}}},
            {4, {{0, 1, {1, 3, 5}}, {1, 0, {2, 5, 6}}}},
            {5, {{0, -1, {1, 4, 6}}, {-1, 0, {2, 3, 4}}}},
            {6, {{0, 1, {1, 3, 5}}, {-1, 0, {2, 3, 4}}}}
        };

        grid_ = grid;
        n = grid.size();
        m = grid[0].size();
        visited.assign(n, vector<bool>(m, false));

        return dfs(0, 0);
    }
};