class Solution {
    int maxOR = 0;
    int solve(auto& nums, int currOR, int pos) {
        if (pos < 0) {
            if (currOR == maxOR)
                return 1;
            else
                return 0;
        }
        
        int include = solve(nums, nums[pos] | currOR, pos - 1);
        int exclude = solve(nums, currOR, pos - 1);


        return include + exclude;
    }
public:
    int countMaxOrSubsets(vector<int>& nums) {
        int n = nums.size();
        for (int& num: nums) {
            maxOR = maxOR | num;
        }

        return solve(nums, 0, n - 1);
    }

};