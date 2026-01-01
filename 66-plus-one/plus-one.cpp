class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        digits[digits.size() - 1] = (digits[digits.size() - 1] + 1) % 10;
        for (int n = digits.size(), i = n - 2; i >= 0; i--) {
            if (digits[i + 1] == 0) {
                digits[i] = (1 + digits[i]) % 10;
            } else {
                break;
            }
        }

        if (digits.front() == 0) {
            digits.insert(digits.begin(), 1);
        }
        return digits;
    }
};