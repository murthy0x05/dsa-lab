class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        int n = nums.size();
        vector<int> counts(101, 0);

        int maxi = 0, result = 0;
        for (const int& num: nums) {
            counts[num]++;
            if (maxi == counts[num]) {
                result += maxi;
            } else if (counts[num] > maxi) {
                maxi = counts[num];
                result = maxi;
            }
        }

        return result;
    }
};