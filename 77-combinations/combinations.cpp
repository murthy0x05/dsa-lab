class Solution {
    vector<vector<int>> combinations;
    void solve(int& k, int& n, auto& combination, int size, int pos) {
        if (k == size) {
            combinations.push_back(combination);
            return ;
        }
        if (pos == n + 1) {
            return ;
        }

        combination.push_back(pos);
        solve(k, n, combination, size + 1, pos + 1);
        combination.pop_back();

        solve(k, n, combination, size, pos + 1);
    }
public:
    vector<vector<int>> combine(int n, int k) {
        vector<int> combination;
        solve(k, n, combination, 0, 1);

        return combinations;
    }
};