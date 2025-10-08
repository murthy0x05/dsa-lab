class Solution {
    using ll = long long;
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        int n = spells.size();
        int m = potions.size();
        
        // si * pi >= success
        // pi >= success / si
        
        sort(potions.begin(), potions.end());

        vector<int> result(n);
        for (int i = 0; i < n; i++) {
            result[i] = m - (lower_bound(potions.begin(), potions.end(), ceil(1.0 * success / spells[i])) - potions.begin());
        }

        return result;




    }
};