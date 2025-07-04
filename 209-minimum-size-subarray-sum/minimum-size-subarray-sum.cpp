class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size();
        int start = 0, end = 0;
        int minLen = INT_MAX;
        int currSum = 0;
        while (start < n) {
            while (end < n && currSum < target) {
                currSum += nums[end];
                end += 1;
            }
            if (currSum >= target)
                minLen = min(minLen, end - start);
            currSum -= nums[start];
            start += 1;
        }


        return minLen == INT_MAX ? 0 : minLen;
    }
};