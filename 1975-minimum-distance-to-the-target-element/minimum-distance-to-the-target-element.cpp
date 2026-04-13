class Solution {
public:
    int getMinDistance(vector<int>& nums, int target, int start) {
        const int N = nums.size();

        int Min = INT_MAX;
        for (int i = 0; i < N; i++) {
            if (nums[i] == target) {
                Min = min(Min, abs(i - start));
            }
        }

        return Min;
    }
};