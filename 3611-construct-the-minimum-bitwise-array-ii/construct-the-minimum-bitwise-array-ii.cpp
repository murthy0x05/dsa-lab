class Solution {
public:
    inline vector<int> minBitwiseArray(vector<int>& nums) {
        int n = nums.size();

        vector<int> arr; arr.reserve(n);
        for (int i = 0; i < n; i++) {
            if (nums[i] & 1) {
                arr.push_back((~((~nums[i] & -(~nums[i])) >> 1)) & nums[i]);
            } else {
                arr.push_back(-1);
            }
        }

        return arr;
    }
};