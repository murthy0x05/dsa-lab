class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        nums.push_back(1e9 + 7);
        const int N = nums.size();

        sort(nums.begin(), nums.end());

        long long d = 1;
        while (true) {
            if (*lower_bound(nums.begin(), nums.end(), k * d) != k * d) {
                return k * d;
            } 

            d += 1;
        }

        return -1;
    }
};