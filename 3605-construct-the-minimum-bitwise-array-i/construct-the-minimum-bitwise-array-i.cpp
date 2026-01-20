class Solution {
public:
    vector<int> minBitwiseArray(vector<int>& nums) {
        int n = nums.size();

        vector<int> arr;
        arr.reserve(n);
        arr.resize(n);
        for (int i = 0; i < n; i++) {
            if (nums[i] & 1) {
                arr[i] = (~((~nums[i] & -(~nums[i])) >> 1)) & nums[i];
            } else {
                arr[i] = -1;
            }
        }

        return arr;
    }
};  