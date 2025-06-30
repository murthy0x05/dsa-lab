class Solution {
    int getValue(int x, int y, char operation) {
        switch (operation) {
            case '+':
                return x + y;
            case '-':
                return x - y;
            case '*':
                return x * y;
            case '/':
                return x / y;
            default:
                return -1;
        }
    }
public:
    int evalRPN(vector<string>& tokens) {
        int n = tokens.size();

        stack<int> st;
        for (string token: tokens) {
            if (isdigit(token.back())) {
                st.push(stoi(token));
            } else {
                int y = st.top(); st.pop();
                int x = st.top(); st.pop();
                st.push(getValue(x, y, token[0]));
            }
        }

        return st.top();
    }
};