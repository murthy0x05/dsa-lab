class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {
        const int R = grid.size(),
                  C = grid[0].size();

        vector<int> nums;
        for (int i = 0; i < R; i++) {
            for (int j = 0; j < C; j++) {
                nums.push_back(grid[i][j]);
            }
        }

        const int N = nums.size();
        sort(nums.begin(), nums.end());
        for (int i = 1; i < N; i++) {
            if ((nums[i] - nums[0]) % x) {
                return -1;
            }
        }

        int cost = 0;
        int median = nums[N >> 1];
        for (int i = 0; i < N; i++) {
            cost += abs(median - nums[i]) / x;
        }

        return cost;
    }
};