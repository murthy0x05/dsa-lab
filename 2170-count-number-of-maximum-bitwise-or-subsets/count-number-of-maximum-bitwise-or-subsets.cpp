class Solution {
    int maxOR = 0;
    vector<vector<int>> mem;
    int solve(auto& nums, int currOR, int pos) {
        if (pos < 0) {
            if (currOR == maxOR)
                return 1;
            else
                return 0;
        }
        
        if (mem[pos][currOR] != -1) {
            return mem[pos][currOR];
        }
        int include = solve(nums, nums[pos] | currOR, pos - 1);
        int exclude = solve(nums, currOR, pos - 1);


        return mem[pos][currOR] = include + exclude;
    }
public:
    int countMaxOrSubsets(vector<int>& nums) {
        int n = nums.size();
        for (int& num: nums) {
            maxOR |= num;
        }
        mem.assign(n, vector<int>(maxOR + 1, -1));

        return solve(nums, 0, n - 1);
    }

};