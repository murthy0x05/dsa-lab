class Solution {
public:
    string shiftingLetters(string s, vector<int>& shifts) {
        int n = s.size();
        vector<int> prefixSum(n + 1, 0);
        for (int i = 0, len = shifts.size(); i < len; i++) {
            shifts[i] %= 26;
            prefixSum[0] += shifts[i];
            prefixSum[i + 1] -= shifts[i]; 
        }

        for (int i = 1; i < n + 1; i++) {
            prefixSum[i] += prefixSum[i - 1];
        }
        string result = "";
        for (int i = 0; i < n; i++) {
            result.push_back(((s[i] - 'a' + prefixSum[i]) % 26) + 'a');
        }

        return result;
    }
};