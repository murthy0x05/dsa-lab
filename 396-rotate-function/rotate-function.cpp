class Solution {
public:
    int maxRotateFunction(vector<int>& nums) {
        const int N = nums.size();

        long long total = 0LL;
        long long F = 0LL;
        for (int i = 0; i < N; i++) {
            total += nums[i];
            F += nums[i] * i;
        }

        int lastId = N - 1;
        long long maxF = F;
        for (int rot = 0; rot < N; rot++) {
            maxF = max(maxF, F);
            F += total - (N * nums[lastId--]);
        }

        return maxF;
    }
};