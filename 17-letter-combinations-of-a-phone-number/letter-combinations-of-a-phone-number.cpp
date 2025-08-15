class Solution {
    vector<string> result;
    string digits; int n;
    vector<string> letters = {"abc", "def",
                              "ghi", "jkl",
                              "mno", "pqrs",
                              "tuv", "wxyz"};
    void backtrack(string& combination, int i) {
        if (i == n) {
            result.push_back(combination);
            return ;
        }

        for (const char& c: letters[digits[i] - '2']) {
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