class Solution {
public:
    int rotatedDigits(int n) {
        int result = 0;
        for (int i = 1; i <= n; i++) {
            string s = to_string(i);
            if (s.find('3') != string::npos ||
                s.find('4') != string::npos ||
                s.find('7') != string::npos)
            {
                continue;
            }

            if (s.find('2') == string::npos &&
                s.find('5') == string::npos &&
                s.find('6') == string::npos &&
                s.find('9') == string::npos)
            {
                continue;
            }

            result++;
        }

        return result;        
    }
};