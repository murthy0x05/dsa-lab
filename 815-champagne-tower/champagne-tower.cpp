class Solution {
public:
    double champagneTower(int poured, int query_row, int query_glass) {
        if (query_row == 0) {
            return poured >= 1;
        }

        vector<double> prev(1, poured);
        for (int i = 1; i <= query_row; i++) {
            int len = prev.size();
            vector<double> curr(len + 1, 0.0);
            curr[0] = (prev[0] > 1.0) ? ((prev[0] - 1.0) / 2.0) : 0.0;
            for (int j = 1; j < len; j++) {
                curr[j] = ((prev[j - 1] > 1.0) ? ((prev[j - 1] - 1.0) / 2.0) : 0.0) +
                          ((prev[j] > 1.0) ? ((prev[j] - 1.0) / 2.0) : 0.0);
            }
            curr[len] = (prev[len - 1] > 1.0) ? ((prev[len - 1] - 1.0) / 2.0) : 0.0;
            
            prev = curr;
        }

        return prev[query_glass] >= 1.0 ? 1.0 : prev[query_glass];
    }
};