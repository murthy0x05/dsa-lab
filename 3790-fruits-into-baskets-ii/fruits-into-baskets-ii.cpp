class Solution {
public:
    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
        int n = fruits.size(), unplaced = 0;
        vector<bool> placed(n, false);

        for (int i = 0; i < n; i++) {
            unplaced++;
            for (int j = 0; j < n; j++) {
                if (!placed[j] && fruits[i] <= baskets[j]) {
                    placed[j] = true;
                    unplaced--;
                    break;
                }
            }
        }

        return unplaced;
    }
};