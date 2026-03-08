class Solution {
public:
    string findDifferentBinaryString(vector<string>& nums) {
        const int N = nums.size();

        set<int> seen;
        for (int i = 0; i < N; i++) {
            seen.insert(stoi(nums[i], nullptr, 2));
        }

        for (int i = 0, len = 1 << N; i < len; i++) {
            if (seen.find(i) == seen.end()) {
                string result = bitset<16>(i).to_string();
                return result.substr(16 - N, N);
            }
        }

        return "";
    }
};