class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        int currlen = 1, maxlen = 1, n = nums.size();

        for (int i = 1; i < n; i++) {
            if (nums[i] > nums[i - 1]) {
                currlen += 1;
                maxlen = max(maxlen, currlen);
            } else {
                currlen = 1;
            }
        }

        return maxlen;
    }
};