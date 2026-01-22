class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int right = accumulate(nums.begin(), nums.end(), 0);
        int left = 0;
        for (int i = 0, n = nums.size(); i < n; i++) {
            if (left == right - nums[i]) {
                return i;
            } else {
                left += nums[i];
                right -= nums[i];
            }
        }

        return -1;
    }
};