class Solution {
public:
    int countMajoritySubarrays(vector<int>& nums, int target) {
        const int N = nums.size();

        int result = 0;
        for (int i = 0; i < N; i++) {
            int tf = 0;
            for (int j = i; j < N; j++) {
                if (nums[j] == target) {
                    tf++;
                }
                if (tf > ((j - i + 1) >> 1)) {
                    result++;
                }
            }
        }

        return result;
    }
};