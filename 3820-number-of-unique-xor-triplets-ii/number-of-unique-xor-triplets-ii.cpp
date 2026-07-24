class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        const int N = nums.size();

        unordered_set<int> have;
        for (int i = 0; i < N; i++) {
            for (int j = i; j < N; j++) {
                have.insert(nums[i] ^ nums[j]);
            }
        }

        unordered_set<int> result;
        for (int k = 0; k < N; k++) {
            for (const int& val: have) {
                result.insert(nums[k] ^ val);
            }
        }

        return result.size();
    }
};