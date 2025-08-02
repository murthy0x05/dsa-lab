class Solution {
    typedef long long ll;
public:
    long long minCost(vector<int>& b1, vector<int>& b2) {
        int n = b1.size();
        unordered_map<int, int> c1, c2;
        int minVal = INT_MAX;
        for (int i = 0; i < n; i++) {
            c1[b1[i]]++;
            c2[b2[i]]++;
            minVal = min<int>({minVal, b1[i], b2[i]});
        }

        vector<int> toSwap;
        for (const auto& [cost, occ]: c1) {
            int occ1 = occ, occ2 = c2[cost];
            int diff = abs(occ1 - occ2);
            if (diff & 1) return -1;
            diff = diff / 2;
            while (diff--) {
                toSwap.push_back(cost);
            }
            c1[cost] = c2[cost] = 0;
        }

        for (const auto& [cost, occ]: c2) {
            int occ1 = c1[cost], occ2 = occ;
            int diff = abs(occ1 - occ2);
            if (diff & 1) return -1;
            diff = diff / 2;
            while (diff--) {
                toSwap.push_back(cost);
            }
            c1[cost] = c2[cost] = 0;
        }

        sort(toSwap.begin(), toSwap.end());

        long long result = 0;
        for (int i = 0; i < toSwap.size() / 2; i++) {
            result += min<ll>(2ll * minVal, toSwap[i]);
        }

        return result;
        



    }
};