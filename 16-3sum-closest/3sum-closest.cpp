class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());

        int closest = -1, abs_sum = 100000;
        for (int i = 0, len = nums.size() - 2; i < len; i++) {
            int l = i + 1, r = len + 1;
            while (l < r) {
                int sum = nums[i] + nums[l] + nums[r];
                if (abs(sum - target) < abs_sum) {
                    abs_sum = abs(sum - target);
                    closest = sum;
                } 
                if (sum - target < 0) {
                    l++;
                } else {
                    r--;
                }
            }
        }

        return closest;
    }
};