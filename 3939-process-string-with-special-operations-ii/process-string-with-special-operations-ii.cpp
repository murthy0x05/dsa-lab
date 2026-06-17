class Solution {
public:
    char processStr(string s, long long k) {
        vector<long long> len(s.size());
        long long currlen = 0;
        
        for (int i = 0; i < s.size(); ++i) {
            char ch = s[i];
            if (ch >= 'a' && ch <= 'z') {
                ++currlen;
            } else if (ch == '*') {
                if (currlen > 0) --currlen;
            } else if (ch == '#') {
                currlen *= 2;
            }
            
            len[i] = currlen;
        }

        if (k >= currlen) return '.';

        for (int i = s.size() - 1; i >= 0; --i) {
            char ch = s[i];

            if (ch >= 'a' && ch <= 'z') {
                if (--currlen == k) return ch;
            } else if (ch == '*') {
                ++currlen;
            } else if (ch == '#') {
                if (k >= currlen / 2) {
                    k -= currlen / 2;
                }
                currlen /= 2;
            } else if (ch == '%') {
                k = currlen - 1 - k;
            }
        }

        return '.';
    }
};