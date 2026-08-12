class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        const int N = nums.size();

        int longest = 0;
        unordered_map<int, int> occ;
        for (int l = -1, r = 0; r < N; r++) {
            occ[nums[r]]++;

            while (occ[nums[r]] > k) {
                ++l;
                occ[nums[l]]--;
            }

            longest = max(longest, r - l);
        }

        return longest;
    }
};