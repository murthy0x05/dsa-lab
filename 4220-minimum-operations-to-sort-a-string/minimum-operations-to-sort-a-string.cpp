class Solution {
public:
    int minOperations(string s) {
        const int N = s.size();
        if (N == 1) {
            return 0;
        }
        if (N == 2) {
            return (s[0] > s[1]) ? -1 : 0;
        }

        bool sorted = true;
        for (int i = 1; i < N; i++) {
            if (s[i - 1] > s[i]) {
                sorted = false;
                break;
            }
        }
        if (sorted) return 0;

        char smallest = *min_element(s.begin(), s.end());
        char largest = *max_element(s.begin(), s.end());

        int cs = count(s.begin(), s.end(), smallest);
        int cl = count(s.begin(), s.end(), largest);
        if (smallest == s[0] || largest == s[N - 1]) {
            return 1;
        }
        if (cl == 1 && largest == s[0] && cs == 1 && smallest == s[N - 1]) {
            return 3;
        }

        return 2;
    }
};