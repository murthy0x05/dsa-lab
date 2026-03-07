class Solution {
public:
    int minFlips(string s) {
        const int N = s.size();

        bool curr1 = false,
             curr2 = true;
        int ops1 = 0,
            ops2 = 0;
        for (int i = 0; i < N; i++) {
            bool curr = (s[i] == '1');
            if (curr1 != curr) {
                ops1++;
            }
            if (curr2 != curr) {
                ops2++;
            }
            curr1 = !curr1;
            curr2 = !curr2;
        }

        int least = min(ops1, ops2);
        for (int i = 0; i < N; i++) {
            bool prefix = s[i] == '1';
            if (curr1 != prefix) {
                ops1++;
            }
            if (curr2 != prefix) {
                ops2++;
            }
            if ((i & 1) != prefix) {
                ops1--;
            }
            if ((!(i & 1)) != prefix) {
                ops2--;
            }

            least = min({least, ops1, ops2});
            curr1 = !curr1;
            curr2 = !curr2;
        }

        return least;
    }
};