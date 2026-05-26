class Solution {
public:
    void sortColors(vector<int>& nums) {
        const int N = nums.size();

        for (int l = 0, r = N - 1, m = 0; m <= r; m++) {
            if (nums[m] == 0) {
                swap(nums[m], nums[l]);
                l++;
            } else if (nums[m] == 1) {
            } else {
                swap(nums[m], nums[r]);
                m--;
                r--;
            }
        }
    }
};