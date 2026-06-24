class Solution {
public:
    bool search(vector<int>& nums, int target) {
        const int N = nums.size();

        int l = 0, r = N - 1;
        while (l <= r) {
            if (target == nums[l]) return true;
            while (l < r && nums[l] == nums[r]) {
                l++;
                r--;
            }

            int mid = l + ((r - l) >> 1);
            if (nums[mid] == target) {
                return true;
            } else if (nums[mid] >= nums[l]) {
                if (target >= nums[l] && target < nums[mid]) {
                    r = mid - 1;
                } else {
                    l = mid + 1;
                }
            } else {
                if (target <= nums[r] && target > nums[mid]) {
                    l = mid + 1;
                } else {
                    r = mid - 1;
                }
            }
        }

        return false;
    }
};