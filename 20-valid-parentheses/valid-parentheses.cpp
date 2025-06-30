class Solution {
public:
    inline bool isValid(string s) {
        int n = s.size();
        unordered_map<char, char> map = {{')', '('}, {'}', '{'}, {']', '['}};
        
        stack<char> st;
        for (int i = 0; i < n; i++) {
            if (map.count(s[i])) {
                if (!st.empty() && st.top() == map[s[i]]) {
                    st.pop();
                } else {
                    return false;
                }
            } else {
                st.push(s[i]);
            }
        }

        return st.empty();
    }
};