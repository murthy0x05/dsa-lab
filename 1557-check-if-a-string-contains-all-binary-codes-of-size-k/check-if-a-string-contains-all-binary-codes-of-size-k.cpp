class Solution {
public:
    bool hasAllCodes(string s, int k) {
        const int N = s.size();
        int comb = 1 << k;
        if (N < (comb - k + 1))
            return false;

        vector<bool> seen(comb, false);
        for (int i = 0, len = N - k + 1; i < len; i++) {
            int val = stoi(s.substr(i, k), nullptr, 2);
            seen[val] = true;
        }

        return *min_element(seen.begin(), seen.end()) == 1;
    }
};