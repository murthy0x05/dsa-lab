class Solution {
public:
    int countBinarySubstrings(string s) {
        const int N = s.size();
        
        int result = 0;
        for (int l = 0, r = 0, po = 0, st; r < N; po = l, l = r) {
            st = l;
            while (l < N && s[l] == '0') {
                l++;
            }
            r = l;
            while (r < N && s[r] == '1') {
                r++;
            }

            result += min(l - st, r - l);
            result += min(l - st, st - po);
        }

        return result;
    }
};