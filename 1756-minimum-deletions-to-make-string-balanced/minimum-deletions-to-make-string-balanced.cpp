class Solution {
public:
    int minimumDeletions(string s) {
        const int N = s.size();

        int ar = count(s.begin(), s.end(), 'a');
        int br = N - ar;
        int minOps = min(ar, br);
        int al = 0, bl = 0;
        for (int i = 0; i < N; i++) {
            if (s[i] == 'a') {
                al++; ar--;
            } else {
                bl++; br--;
            }

            minOps = min(minOps, bl + ar);
        }

        return minOps;
    }
};