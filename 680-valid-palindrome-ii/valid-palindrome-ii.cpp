class Solution {
public:
    bool validPalindrome(string s) {
        int n = s.size();

        function<bool(int, int)> check = [&] (int l, int r) {
            while (l < r) {
                if (s[l] != s[r]) {
                    return false;
                }
                l++; r--;
            }

            return true;
        };

        int l = 0, r = n - 1;
        while (l < r) {
            if (s[l] == s[r]) {
                l++; r--;
            } else {
                return check(l + 1, r) || check(l, r - 1);
            }
        }

        return true;
    }
};