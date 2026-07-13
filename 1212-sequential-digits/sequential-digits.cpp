class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        int N1 = log10(low) + 1,
            N2 = log10(high) + 1;

        vector<int> result;
        for (int L = N1; L <= N2; L++) {
            for (int s = 1; s <= (9 - L + 1); s++) {
                int l = 1;
                long val = s;
                while (l < L) {
                    val = val * 10 + (val % 10 + 1);
                    l += 1;
                }

                if (val >= low and val <= high) {
                    result.push_back(val);
                }
            }
        }

        return result;
    }
};