class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        int n = nums.size();
        unordered_set<int> seen;

        int start = 0, end = 0, curr_sum = 0, max_sum = 0;
        while (start < n) {
            while (end < n && !seen.count(nums[end])) {
                seen.insert(nums[end]);
                curr_sum += nums[end];
                end++;
            }
            max_sum = max(max_sum, curr_sum);
            if (end == n) break;
            while (start < n && seen.find(nums[end]) != seen.end()) {
                seen.erase(nums[start]);
                curr_sum -= nums[start];
                start++;
            }
        }

        return max_sum;
    }
};