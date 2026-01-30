class Solution {
public:
    int splitArray(vector<int>& nums, int k) {
        int n = nums.size();

        function<bool(int&)> feasible = [&](int& total) {
            int K = 1;
            int sum = 0;
            for (int i = 0; i < n; i++) {
                if (sum + nums[i] > total) {
                    sum = 0;
                    K++;
                }
                sum += nums[i];
            }

            return K <= k;
        };

        int low = *max_element(nums.begin(), nums.end()),
            high = accumulate(nums.begin(), nums.end(), 0);
        int result = 0;
        while (low <= high) {
            int mid = low + ((high - low) >> 1);
            if (feasible(mid)) {
                result = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        return result;
    }
};