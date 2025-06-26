class Solution {
public:
    int longestSubsequence(string s, int k) {
        int n = s.size();
        int weight = 0;

        int result = 0;
        for (int i = n - 1; i >= 0; i--) {
            if ('1' == s[i]) {
                if (std::pow(2, (n - 1) - i) + weight <= k) {
                    result += 1;
                    weight += pow(2, (n-1) - i);
                }
            } else {
                result += 1;
            }
        }

        return result;
    }
};