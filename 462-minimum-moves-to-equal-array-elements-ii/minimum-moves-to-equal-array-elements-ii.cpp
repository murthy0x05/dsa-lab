class Solution {
public:
    int minMoves2(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int median = nums[n >> 1];
        int moves = 0;

        for (int& num: nums) {
            moves += abs<int>(num - median);
        }

        return moves;
    }
};