class Solution {
    using ll = long long;
public:
    string fractionToDecimal(int numerator, int denominator) {
        if (numerator == 0) return "0";

        bool ve = (numerator < 0) ^ (denominator < 0);
        ll n = abs<ll>(numerator * 1LL);
        ll d = abs<ll>(denominator * 1LL);
        if (d == 1) return ((ve) ? "-" : "") + to_string(n);
        cout << " I am here " << endl;
        if (!(n % d)) {
            return ((ve) ? "-" : "") + to_string(n / d);
        }

        string result = ((ve) ? "-" :  "") + to_string(n / d) + ".";
        ll rem = n % d;
        unordered_map<ll, int> seen;

        while (rem != 0) {
            if (seen.count(rem)) {
                result.insert(seen[rem], 1, '(');
                result.push_back(')');
                return result;
            }
            
            seen[rem] = result.size();
            rem *= 10;
            result += to_string(rem / d);
            rem %= d;
        }

        return result;
    }
};