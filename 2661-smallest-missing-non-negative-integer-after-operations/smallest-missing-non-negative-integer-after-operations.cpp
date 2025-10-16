class Solution {
public:
    int findSmallestInteger(vector<int>& nums, int value) {
        int n = nums.size();

        vector<int> counts(value + 1, 0);
        for (int i = 0; i < n; i++) {
            counts[((nums[i] % value) + value) % value]++;
        }

        for (int i = 0; i < n; i++) {
            if (counts[i % value] == 0) return i;
            else {
                counts[i % value]--;
            } 
        }


        return n;
    }
};