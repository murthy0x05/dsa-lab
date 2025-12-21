class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int r = strs.size(),
            c = strs[0].size();

        unordered_set<int> deleted;
        vector<vector<int>> stoppedAt;
        function<int(int, int, int)> dfs = [&](int col, int rs, int re) {
            if (col >= c) {
                return 0;
            }

            int len = 1;
            vector<pair<int, int>> blocks;
            for (int i = rs + 1; i <= re; i++) {
                if (strs[i - 1][col] != strs[i][col]) {
                    if (strs[i - 1][col] > strs[i][col]) {
                        cout << "Row: " << i << ' ' << "Col: " << col << endl;
                        deleted.insert(col);
                        dfs(col + 1, rs, re);
                        return (int)deleted.size();
                    } else {
                        if (len > 1) {
                            blocks.push_back(make_pair(i - len, i - 1));
                        }
                        len = 1;
                    }
                } else {
                    len++;
                }
            }
            if (len > 1) {
                blocks.push_back(make_pair(re - len + 1, re));
            }
            stoppedAt.push_back({col, rs, re});
            

            for (pair<int, int>& block: blocks) {
                dfs(col + 1, block.first, block.second);
            }

            return (int)deleted.size();
        };
        
        dfs(0, 0, r - 1);

size_t n = stoppedAt.size();
for (size_t i = 0; i < n; ++i) {
    auto &at = stoppedAt[i];
    if (deleted.count(at[0])) {
        dfs(at[0] + 1, at[1], at[2]);
    }
}


        return deleted.size();
    }
};