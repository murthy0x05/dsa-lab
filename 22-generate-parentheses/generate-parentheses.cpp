class Solution {
public:
    vector<string> generateParenthesis(int n, string paren = "", int open = 0, int close = 0) {
        vector<string> validParens;
        if (open == n && close == n) {
            validParens.push_back(paren);
            return validParens;
        }

        if (open < n) {
            vector<string> temp = generateParenthesis(n, paren + "(", open + 1, close);
            for (string& t: temp) {
                validParens.push_back(t);
            }
        }

        if (close < open) {
            vector<string> temp = generateParenthesis(n, paren + ")", open, close + 1);
            for (string& t: temp) {
                validParens.push_back(t);
            }
        }

        return validParens;
    }
};