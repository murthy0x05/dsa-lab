class Solution {
public:
    vector<int> separateDigits(vector<int>& nums) {
        const int N = nums.size();
        
        vector<int> digits;
        for (int i = 0; i < N; i++) {
            for (const char& c: to_string(nums[i])) {
                digits.push_back(c - '0');
            }
        }

        return digits;
    }
};