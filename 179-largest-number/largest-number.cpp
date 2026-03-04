class Solution {
public:
    string largestNumber(vector<int>& nums) {
        const int N = nums.size();

        sort(nums.begin(), nums.end(), [&] (const int& a, const int& b) {
            string ab = to_string(a) + to_string(b);
            string ba = to_string(b) + to_string(a);
            return stoull(ab, nullptr, 10) > stoull(ba, nullptr, 10);
        });

        if (nums.front() == 0) {
            return "0";
        }

        string result;
        for (int i = 0; i < N; i++) {
            result += to_string(nums[i]);
        }

        return result;
    }
};