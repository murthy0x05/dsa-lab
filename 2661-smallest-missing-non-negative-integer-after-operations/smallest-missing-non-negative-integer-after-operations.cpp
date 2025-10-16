class Solution {
public:
    int findSmallestInteger(vector<int>& nums, int value) {
        int n = nums.size();

        unordered_map<int, int> counts;
        for (int i = 0; i < n; i++) {
            int mod = ((nums[i] % value) + value) % value;
            counts[mod]++;
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