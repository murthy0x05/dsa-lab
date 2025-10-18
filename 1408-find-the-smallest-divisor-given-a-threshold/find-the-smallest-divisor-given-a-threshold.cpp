class Solution {
    int n;
    bool feasible(const vector<int>& nums, const int& threshold, const int& mid) {
        int result = 0;
        for (int i = 0; i < n; i++) {
            result += (nums[i] + mid - 1) / mid;
        }

        return result <= threshold;
    }
public:
    int smallestDivisor(vector<int>& nums, int threshold) {
        this -> n = nums.size();

        int low = 1, high = 1e6;
        int ans = high;
        while (low <= high) {
            int mid = low + ((high - low) >> 1);
            if (feasible(nums, threshold, mid)) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        return ans;
    }
};