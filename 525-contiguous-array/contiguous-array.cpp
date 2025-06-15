class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int n = nums.size();
        int sum = 0;
        unordered_map<int, int> seen;
        seen[0] = -1;

        int maxLen = 0;
        for (int i = 0; i < n; i++) {
            sum += nums[i] == 0 ? -1 : 1;
            if (seen.find(sum) != seen.end()) {
                maxLen = max(maxLen, i - seen[sum]);
            } else {
                seen[sum] = i;
            }
        }

        return maxLen;


    }
};