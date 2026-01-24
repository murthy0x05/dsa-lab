class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n = nums.size();

        int low = 0, high = n - 1;
        while (low <= high) {
            int mid = low + ((high - low) >> 1);
            if (mid == low || mid == high || ((nums[mid] != nums[mid - 1]) && (nums[mid] != nums[mid + 1]))) {
                return nums[mid];
            } else if ((high - mid) & 1) {
                if (nums[mid] == nums[mid + 1]) {
                    high = mid - 1;
                } else {
                    low = mid + 1;
                }
            } else {
                if (nums[mid] == nums[mid + 1]) {
                    low = mid + 2;
                } else {
                    high = mid - 2;
                }
            }
        }

        return -1;
    }
};