class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n = nums.size();

        int len = 0;
        for (int l = 0, r = 0, z = 0; r < n; r++) {
            z += nums[r] == 0;
            if (z > k) {
                z -= nums[l] == 0;
                l++;
            }

            len = max(len, r - l + 1);
        }

        return len;
    }
};