class Solution {
public:
    string shiftingLetters(string s, vector<int>& shifts) {
        int n = s.size();
        long long totalShifts = 0;

        string result(n, '\0');
        for (int i = n - 1; i >= 0; i--) {
            totalShifts = (totalShifts + shifts[i]) % 26;
            result[i] = ((s[i] - 'a' + totalShifts) % 26 + 'a');
        }

        return result;
    }
};