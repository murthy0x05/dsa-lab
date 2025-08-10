class Solution {
    #define ll long long
public:
    bool reorderedPowerOf2(int n) {
        function<string(int&)> toSortedString = [](int& n) {
            string s = to_string(n);
            sort(s.begin(), s.end());

            return s;
        };

        string strN = toSortedString(n); int bit = 0;
        for (int i = 0; i < 32; i++) {
            int twoPower = 1 << i;
            if (strN == toSortedString(twoPower)) return true;
        }

        return false;
    }
};