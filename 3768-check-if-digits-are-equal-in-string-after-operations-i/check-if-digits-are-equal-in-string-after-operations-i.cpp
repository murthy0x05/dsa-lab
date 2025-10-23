class Solution {
public:
    bool hasSameDigits(string s) {
        int n = s.size();
        
        for (int i = 0; i < n - 2; i++) {
            for (int j = 0; j < n - i - 1; j++) {
                s[j] = (s[j] + s[j + 1] - 2 * '0') % 10 + '0';
            }
        }
        
        return s[0] == s[1];
    }
};