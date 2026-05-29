class Solution {
public:
    int minElement(vector<int>& nums) {
        const int N = nums.size();

        int minSol = 10000;
        for (int i = 0; i < N; i++) {
            int sum = 0;
            while (nums[i] > 0) {
                sum += nums[i] % 10;
                nums[i] /= 10;
            }

            minSol = min(sum, minSol);
        }

        return minSol;
    }
};