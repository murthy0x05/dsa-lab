class Solution {
public:
    int longestBalanced(vector<int>& nums) {
        const int N = nums.size();

        int result = 0;
        for (int i = 1; i < N; i++) {
            unordered_set<int> seen = {nums[i]};
            int even = !(nums[i] & 1), odd = (nums[i] & 1);

            for (int j = i - 1; j >= 0; j--) {
                if (!seen.count(nums[j])) {
                    even += !(nums[j] & 1);
                    odd += (nums[j] & 1);
                    seen.insert(nums[j]);
                }
                if (even == odd)
                    result = max(result, i - j + 1);
            }
        }

        return result;
    }
};