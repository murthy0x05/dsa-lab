class Solution {
public:
    int xorAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        const int MOD = 1e9 + 7;

        for (const vector<int>& query: queries) {
            for (int i = query[0]; i <= query[1]; i += query[2]) {
                nums[i] = (nums[i] * 1LL * query[3]) % MOD;
            }
        }

        int result = 0;
        for (const int& num: nums) {
            result = result ^ num;
        }  

        return result;
    }
};