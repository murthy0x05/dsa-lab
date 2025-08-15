class Solution {
    vector<string> result;
    string digits; int n;
    string letters(int n) {
        if (n == 2) return "abc";
        if (n == 3) return "def";
        if (n == 4) return "ghi";
        if (n == 5) return "jkl";
        if (n == 6) return "mno";
        if (n == 7) return "pqrs";
        if (n == 8) return "tuv";
        if (n == 9) return "wxyz";

        return "";
    }
    void backtrack(string& combination, int i) {
        if (i == n) {
            result.push_back(combination);
            return ;
        }

        for (const char& c: letters(digits[i] - '0')) {
            combination.push_back(c);
            backtrack(combination, i + 1);
            combination.pop_back();
        }
    }
public:
    vector<string> letterCombinations(string digits) {
        if (digits.size() == 0) return {}; 
        this -> digits = digits;
        n = digits.size();
        string combination("");
        backtrack(combination, 0);

        return result;
    }
};