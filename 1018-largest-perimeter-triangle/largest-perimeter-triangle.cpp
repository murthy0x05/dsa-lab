class Solution {
public:
    int largestPerimeter(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end(), greater<int>());

        int result = 0;
        for (int i = 0; i < n - 2; i++) {
            if (nums[i + 2] + nums[i + 1] > nums[i]) {
                result = max<int>(result, nums[i] + nums[i+1] + nums[i+2]);
            }
        }

        return result;        
    }
};