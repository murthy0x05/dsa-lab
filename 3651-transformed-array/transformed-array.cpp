class Solution {
public:
    vector<int> constructTransformedArray(vector<int>& nums) {
        const int n = nums.size();

        vector<int> result; result.reserve(n);
        for (int i = 0; i < n; i++) {
            if (nums[i] == 0) {
                result.push_back(0);
            } else {
                result.push_back(nums[((i + (nums[i] % n) + n) % n)]);
            }
        }

        return result;
    }
};