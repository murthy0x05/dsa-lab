class Solution {
    bool can_split(vector<int>& nums, int total, int k) {
        int i = 0, n = nums.size(), curr_sum = 0, splits = 0;
        if (*max_element(nums.begin(), nums.end()) > total)
            return false;
        while (i < n) {
            if (curr_sum + nums[i] > total) {
                curr_sum = nums[i];
                splits++;
            } else {
                curr_sum += nums[i];
            }
            i++;
        }

        return splits + 1 <= k;
    }
public:
    int splitArray(vector<int>& nums, int k) {
        int n = nums.size();
        int sum = 0, largest_sum = 0;
        for (int& num: nums) {
            sum += num;
            largest_sum = max(largest_sum, num);
        }
        // cout << sum << endl;

        int low = 0, high = sum;
        while (low <= high) {
            int mid = low + ((high - low) >> 1);
            if (can_split(nums, mid, k)) {
                // cout << mid << endl;
                largest_sum = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        return largest_sum;
    }
};