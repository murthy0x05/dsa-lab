class Solution {
public:
    vector<bool> prefixesDivBy5(vector<int>& nums) {
        int n = nums.size();

        vector<bool> result(n, false);
        for (int i = 0, val = 0; i < n; i++) {
            val = ((val * 2) + nums[i]) % 5;
            result[i] = (val == 0);
        }

        return result;
    }
};