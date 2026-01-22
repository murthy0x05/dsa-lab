class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int n = nums.size();
        function<int(int)> atmost = [&](int K) {
            int l = 0, r = 0;
            int total = 0;
            int result = 0;
            while (r < n) {
                total += nums[r];
                while (total > K) {
                    total -= nums[l];
                    l++;
                }
                result += r - l + 1;
                r++;
            }

            return result;
        };

        return atmost(goal) - (goal ? atmost(goal - 1) : 0);
    }
};