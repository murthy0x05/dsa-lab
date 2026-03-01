class Solution {
public:
    bool isBipartite(vector<vector<int>>& adj) {
        const int N = adj.size();
        vector<short> color(N, -1);
        function<bool(const int&)> dfs = [&] (const int& curr) {
            for (const int& nbr: adj[curr]) {
                if (color[nbr] == color[curr]) {
                    return false;
                } else if (color[nbr] == -1) {
                    color[nbr] = 1 - color[curr];
                    if (!dfs(nbr)) {
                        return false;
                    }
                }
            }

            return true;
        };

        for (int i = 0; i < N; i++) {
            if (color[i] == -1 && (color[i] = 1) && !dfs(i)) {
                return false;
            }
        }

        return true;
    }
};