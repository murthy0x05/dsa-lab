class Solution {
public:
    string largestGoodInteger(string num) {
        char digit = '0' - 1;
        for (int i = 0, len = num.size(); i < len - 2; i++) {
            if (num[i] == num[i + 1] && num[i] == num[i + 2]) {
                digit = max<char>(digit, num[i]);
            }
        }

        return digit >= '0' ? string(3, digit) : "";
    }
};