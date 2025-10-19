class Solution {
    int n;
    string smallest;
    unordered_set<string> seen;
    void solve(string& s, const int& a, const int& b) {
        if (!seen.insert(s).second) {
            return ;
        }
        smallest = min<string>(smallest, s);

        string s1(s), s2;
        for (int i = 1; i < n; i += 2) {
            s1[i] = ((s1[i] - '0' + a) % 10) + '0';
        }
        solve(s1, a, b);
        s2 = s.substr(s.size() - b) + s.substr(0, s.size() - b);
        solve(s2, a, b);
    }
public:
    string findLexSmallestString(string s, int a, int b) {
        this -> n = s.size();
        this -> smallest = s;

        solve(s, a, b);
        return smallest;
    }

    // x + a
    // x + 2*a
    // x + 3*a

    /*
        Observations:
        1. s is guaranteed to be even. equal no. of odd and even indices in every tc.
        2. if b = even, the odd placeholders doesn't change on rotations.
        3. if b = odd, the odd placeholders can also change on rotations.

    */
};

// 5525
// 2555
// 5525

// b = 3
// 12345678
// 2 4 6 8
// 67812345
// 7 1 3 5
// 34567812
// 12345678

// b = 2 even
// 1234
// 2 4
// 3412
// 4 2