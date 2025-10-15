class Solution {
    int n;
    bool feasible(const vector<int>& inc, int mid) {
        for (int i = 0; i < n - mid; i++) {
            if (inc[i] >= mid && inc[i + mid] >= mid) {
                return true;
            }
        }

        return false;
    }
public:
    int maxIncreasingSubarrays(vector<int>& nums) {
        this -> n = nums.size();

        vector<int> inc(n, 0); inc.back() = 1;
        for (int i = n - 2; i >= 0; i--) {
            if (nums[i] < nums[i + 1]) {
                inc[i] = inc[i + 1] + 1;
            } else {
                inc[i] = 1;
            }
        }

        int result = 1;
        int low = 0, high = n / 2;
        while (low <= high) {
            int mid = low + ((high - low) >> 1);
            if (feasible(inc, mid)) {
                result = mid;
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }

        return result;
    }
};