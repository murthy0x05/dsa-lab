class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        const int N = nums.size();

        vector<bool> have(2049);
        for (int i = 0; i < N; i++) {
            for (int j = i; j < N; j++) {
                have[nums[i] ^ nums[j]] = true;
            }
        }

        vector<bool> result(2049);
        for (int k = 0; k < N; k++) {
            for (int x = 0; x < 2049; x++) {
                if (have[x] == 1) {
                    result[nums[k] ^ x] = true;
                }
            }
        }

        cout << (31 - __builtin_clz(1500)) << endl;

        return accumulate(result.begin(), result.end(), 0);
    }
};