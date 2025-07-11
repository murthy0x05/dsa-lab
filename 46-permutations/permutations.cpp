class Solution {
    vector<vector<int>> permutations; int n;
    void backtrack(vector<int>& nums, int pos) {
        if (pos >= n) {
            permutations.push_back(nums);
            return ;
        }
        for (int i = pos; i < n; i++) {
            if (i != pos)
                swap(nums[pos], nums[i]);
            backtrack(nums, pos + 1);
            swap(nums[pos], nums[i]);
        }
    }
public:
    vector<vector<int>> permute(vector<int>& nums) {
        this -> n = nums.size();
        backtrack(nums, 0);
        return permutations;        
    }
};