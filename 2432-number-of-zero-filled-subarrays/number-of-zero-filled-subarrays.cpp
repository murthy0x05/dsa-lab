class Solution {
    #define ll long long
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        int n = nums.size();
        
        ll count = 0;
        int zerolen = 0;
        for (int i = 0; i < n; i++) {
            if (0 == nums[i]) {
                zerolen++;
                count += zerolen;
            } else {
                zerolen = 0;
            }
        }

        return count;
    }
};