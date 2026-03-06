class Solution {
public:
    bool checkOnesSegment(string s) {
        int l = s.find('1');
        int r = s.rfind('1');

        if (l == string::npos) {
            return true;
        }

        return count(s.begin(), s.end(), '1') == (r - l + 1);
    }
};