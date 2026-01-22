class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();

        int i = n - 1;
        while (i > 0 && nums[i - 1] >= nums[i]) {
            i--;
        }

        int used = 0;
        if (i > 0) {
            int low = i, high = n - 1;
            while (low <= high) {
                int mid = low + ((high - low) >> 1);
                if (nums[mid] > nums[i - 1]) {
                    low = mid + 1;
                } else {
                    high = mid - 1;
                }
            }

            used = high;
            swap(nums[i - 1], nums[used]);
        }

        int l = i, r = n - 1;
        while (l < r) {
            swap(nums[l], nums[r]);
            l++; r--;
        }
    }
};