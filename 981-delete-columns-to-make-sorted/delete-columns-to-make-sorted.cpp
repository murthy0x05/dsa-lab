class Solution {
public:
    int minDeletionSize(const vector<string>& strs) {
        int deleted = 0;

        for (int j = 0, r = strs.size(), c = strs[0].size(); j < c; j++) {
            for (int i = 1; i < r; i++) {
                if (strs[i - 1][j] > strs[i][j]) {
                    deleted++;
                    break;
                }
            }
        }

        return deleted;
    }
};