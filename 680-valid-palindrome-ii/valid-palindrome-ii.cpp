class Solution {
public:
    bool validPalindrome(string s) {
        int n = s.size();

        int misplaced = 0;
        function<bool(int, int)> dfs = [&] (int l, int r) {
            if (l >= r) {
                return true;
            }

            if (s[l] == s[r]) {
                return dfs(l + 1, r - 1);
            } else {
                if (misplaced > 0) {
                    return false;
                }
                misplaced++;
                return dfs(l + 1, r) || dfs(l, r - 1);
            }
        };

        return dfs(0, n - 1);
    }
};