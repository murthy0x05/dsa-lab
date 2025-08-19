class Solution {
    int n;
    int solve(string& s, int& i) {
        if (s[i] == '-') {
            i++;
            return -1 * solve(s, i);
        } else if (isdigit(s[i])) {
            int number = 0;
            while (i < n && isdigit(s[i])) {
                number *= 10;
                number += s[i] - '0';
                i++;
            }

            return number;
        } 

        i++;
        int sum = solve(s, i);
        while (s[i] != ')') {
            if (s[i] == '+') {
                i++;
                sum += solve(s, i);
            } else {
                i++;
                sum -= solve(s, i);
            }
        }
        i++;

        return sum;
    }
public:
    int calculate(string s) {
        int idx = 0; n = s.size();
        for (int i = 0; i < n; i++) {
            if (s[i] == ' ') continue;
            s[idx++] = s[i];
        }


        s = s.substr(0, idx);
        n = s.size();
        cout << s << endl;
        int i = 0, ans = solve(s, i);
        while (i < idx) {
            if (s[i] == '+') {
                i++;
                ans += solve(s, i);
            } else {
                i++;
                ans -= solve(s, i);
            }
        }

        return ans;
    }
};