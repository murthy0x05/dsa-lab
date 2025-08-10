class Solution {
    #define ll long long
public:
    bool reorderedPowerOf2(int n) {
        function<string(int&)> toSortedString = [](int& n) {
            string s = to_string(n);
            sort(s.begin(), s.end());

            return s;
        };

        string num = toSortedString(n); int bit = 0;
        for (int bit = 0; bit < 31; bit++) {
            int power = 1 << bit;
            if (num == toSortedString(power)) return true;
        }

        return false;
    }
};