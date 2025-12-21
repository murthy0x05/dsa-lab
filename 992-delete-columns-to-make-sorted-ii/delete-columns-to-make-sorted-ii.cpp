class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int r = strs.size();
        int c = strs[0].size();

        int deleted = 0;
        vector<bool> sorted(r, false);
        for (int j = 0; j < c; j++) {
            bool flag = true;
            for (int i = 1; i < r; i++) {
                if (!sorted[i] && strs[i - 1][j] > strs[i][j]) {
                    flag = false;
                    break;
                }
            }

            if (!flag) {
                deleted++;
                continue;
            }

            for (int i = 1; i < r; i++) {
                if (!sorted[i] && strs[i - 1][j] < strs[i][j]) {
                    sorted[i] = true;
                }
            }
        }

        return deleted;
    }
};