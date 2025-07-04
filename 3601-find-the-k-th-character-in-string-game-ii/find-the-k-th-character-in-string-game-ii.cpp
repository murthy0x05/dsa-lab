class Solution {
public:
    char kthCharacter(long long k, vector<int>& operations) {
        int n = operations.size();
        long long val = k;
        int shifts = 0;

        while (val > 1) {
            int jumps = std::floor(log2(val - 1));
            val = val - std::pow(2, jumps);
            shifts += operations[jumps];
        }

        return 'a' + (shifts % 26);
    }
};