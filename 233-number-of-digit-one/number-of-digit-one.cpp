class Solution {
    using ll = long long;
public:
    int countDigitOne(int n) {
        int result = 0;
        for (ll place = 1; place <= n; place *= 10LL) {
            int higher = n / place;
            int current = higher % 10;
            int lower = n % place;
            higher /= 10;


            if (current == 0) {
                result += higher * place;
            } else if (current == 1) {
                result += (higher * place) + (lower + 1);
            } else {
                result += (higher + 1) * place;
            }
        }

        return result;
    }
};