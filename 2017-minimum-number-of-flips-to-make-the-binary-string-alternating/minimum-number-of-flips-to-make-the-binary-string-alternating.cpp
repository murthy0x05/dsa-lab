class Solution {
public:
    int minFlips(string s) {
        const int N = s.size();

        int ops1 = 0, ops2 = 0;
        for (int i = 0; i < N; i++) {
            if ((i & 1) != (s[i] == '1')) {
                ops1++;
            }
            if ((i & 1 ^ 1) != (s[i] == '1')) {
                ops2++;
            }
        }

        int least = min(ops1, ops2);
        for (int i = 0; i < N - 1; i++) {
            if ((i & 1) != (s[i] == '1')) {
                ops1--;
            }
            if ((1 ^ i & 1) != (s[i] == '1')) {
                ops2--;
            }
            if (((N + i) & 1) != (s[i] == '1')) {
                ops1++;
            }
            if (((N + i) & 1 ^ 1) != (s[i] == '1')) {
                ops2++;
            }
            
            least = min({least, ops1, ops2});
        }

        return least;
    }
};