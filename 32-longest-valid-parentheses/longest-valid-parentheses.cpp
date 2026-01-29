class Solution {
public:
    int longestValidParentheses(string s) {
        int n = s.size();

        vector<int> opp(n);
        stack<int> st;
        for (int i = 0; i < n; i++) {
            if (s[i] == '(') {
                st.push(i);
            } else {
                if (st.empty()) {
                    opp[i] = -1;
                } else {
                    opp[i] = st.top();
                    opp[st.top()] = i;
                    st.pop();
                }
            }
        }

        while (!st.empty()) {
            opp[st.top()] = -1;
            st.pop();
        }

        int Max = 0, curr = 0;
        int i = 0;
        while (i < n) {
            if (opp[i] == -1) {
                Max = max(Max, curr);
                curr = 0;
                i++;
            } else {
                curr += opp[i] - i + 1;
                i = opp[i] + 1;
            }
        }

        return max(Max, curr);
    }
};