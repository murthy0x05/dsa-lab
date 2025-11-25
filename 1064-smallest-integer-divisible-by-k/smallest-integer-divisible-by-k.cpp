class Solution {
public:
    int smallestRepunitDivByK(int k) {
        int mod = 0;

        // unordered_set<int> seen;
        for (int i = 1; i <= k; i++) {
            mod = (mod * 10 + 1) % k;
            // if (seen.count(mod)) return -1;
            // else seen.insert(mod);
            if (!mod) return i;
        }

        return -1;
    }
};