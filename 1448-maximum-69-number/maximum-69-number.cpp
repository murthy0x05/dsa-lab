class Solution {
public:
    int maximum69Number (int num) {
        string num_s = to_string(num);

        for (int i = 0; num_s[i] != '\0'; i++) {
            if (num_s[i] == '6') {
                num_s[i] = '9';
                return stoi(num_s);
            }
        }

        return stoi(num_s);
    }
};