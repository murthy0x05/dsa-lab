class Solution {
public:
    bool isTrionic(vector<int>& nums) {
        const int n = nums.size();

        int i = 1;
        while (i < n && nums[i - 1] < nums[i]) {
            i++;
        }
        if (i < 2 || i >= n || nums[i - 1] == nums[i]) {
            return false;
        }

        while (i < n && nums[i - 1] > nums[i]) {
            i++;
        }
        if (i >= n || nums[i - 1] == nums[i]) {
            return false;
        }
        while (i < n && nums[i - 1] < nums[i]) {
            i++;
        }

        return i == n;
    }
};