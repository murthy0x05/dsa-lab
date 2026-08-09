class Solution {
public:
    int stoneGameVI(vector<int>& aliceValues, vector<int>& bobValues) {
        const int N = aliceValues.size();

        vector<int> ids(N);
        iota(ids.begin(), ids.end(), 0);

        sort(ids.begin(), ids.end(), [&] (const int& id1, const int& id2) {
            return aliceValues[id1] + bobValues[id1] > aliceValues[id2] + bobValues[id2];
        });

        int alice = 0, bob = 0;
        for (int i = 0; i < N; i++) {
            if (i & 1) {
                bob += bobValues[ids[i]];
            } else {
                alice += aliceValues[ids[i]];
            }
        }

        if (alice > bob) return 1;
        if (alice < bob) return -1;
        return 0;
    }
};