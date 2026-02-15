class Solution {
public:
    string addBinary(string a, string b) {
        if (a == "0") {
            return b;
        } else if (b == "0") {
            return a;
        } else {
            string result;
            int i = a.size() - 1, j = b.size() - 1,
                carry = 0, buffer;
            while (i >= 0 && j >= 0) {
                buffer = carry + (a[i] - '0') + (b[j] - '0');
                if (buffer == 0) {
                    carry = 0;
                    result.push_back('0');
                } else if (buffer == 1) {
                    carry = 0;
                    result.push_back('1');
                } else if (buffer == 2) {
                    carry = 1;
                    result.push_back('0');
                } else {
                    carry = 1;
                    result.push_back('1');
                }
                i--; j--;
            }
            while (i >= 0) {
                buffer = carry + (a[i] - '0');
                if (buffer == 0) {
                    result.push_back('0');
                    carry = 0;
                } else if (buffer == 1) {
                    result.push_back('1');
                    carry = 0;
                } else {
                    carry = 1;
                    result.push_back('0');
                }
                i--;
            }
            while (j >= 0) {
                buffer = carry + (b[j] - '0');
                if (buffer == 0) {
                    result.push_back('0');
                    carry = 0;
                } else if (buffer == 1) {
                    result.push_back('1');
                    carry = 0;
                } else {
                    carry = 1;
                    result.push_back('0');
                }
                j--;
            }
            if (carry > 0) {
                result.push_back('1');
            }

            reverse(result.begin(), result.end());
            return result;
        }
    }
};