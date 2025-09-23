class Solution {
public:
    bool isNumber(string s) {
        if (s == ".") return false;

        int n = s.size(),
            i = 0;

        int dot = -1,
            exp = -1;
        
        for (; i < n; i++) {
            if (s[i] == '.') {
                if (dot != -1 || exp != -1) {
                    return false;
                } else {
                    dot = i;
                }
            } else if (s[i] == 'e' || s[i] == 'E') {
                if (exp != -1) {
                    return false;
                } else {
                    exp = i;
                }
            }
        }

        if (exp != -1) {
            string left = s.substr(0, exp);
            string right = s.substr(exp + 1);

            int l = left.size(), r = right.size();
            if (!l || !r) {
                return false;
            }

            int x = 0, y = 0;
            if (left[x] == '+' || left[x] == '-') {
                x++;
            }
            if (right[y] == '+' || right[y] == '-') {
                y++;
            }
            if (x == l || y == r) return false;

            if (l - x == 1 && left[x] == '.') return false; 

            while (x < l && isdigit(left[x])) x++;
            if (dot == -1) {
                if (x < l) return false;
            } else {
                if (dot != x) return false;
                else {
                    x++;
                    while (x < l && isdigit(left[x])) x++;
                    if (x < l) return false;
                }
            }

            while (y < r && isdigit(right[y])) y++;
            if (y < r) return false;
        } else {
            string left = s;

            int l = left.size();
            if (!l) {
                return false;
            }

            int x = 0;
            if (left[x] == '+' || left[x] == '-') {
                x++;
            }

            if (x == l) return false;
            if (l - x == 1 && left[x] == '.') return false; 

            while (x < l && isdigit(left[x])) x++;
            if (dot == -1) {
                if (x < l) return false;
            } else {
                if (dot != x) return false;
                else {
                    x++;
                    while (x < l && isdigit(left[x])) x++;
                    if (x < l) return false;
                }
            }
        }

        return true;
    }
};