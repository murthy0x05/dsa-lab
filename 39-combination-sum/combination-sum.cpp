class Solution {
    vector<vector<int>> combinations;
    int n;
    #define psb push_back
    #define ppb pop_back
    void solve(vector<int>& candidates, vector<int>& combination, int sum, int start, int& target) {

        if (sum == target) {
            combinations.psb(combination);
        } else if (sum < target) {
            for (int i = start; i < n; i++) {
                combination.psb(candidates[i]);
                solve(candidates, combination, sum + candidates[i], i, target);
                combination.ppb();
            }
        }
    }
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        this -> n = candidates.size();
        vector<int> combination;
        solve(candidates, combination, 0, 0, target);

        return combinations;
    }
};