class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        const int r = matrix.size(),
                  c = matrix[0].size();

        int i = r - 1, j = 0;
        while (i >= 0 && j < c) {
            if (matrix[i][j] == target) {
                return true;
            } else if (matrix[i][j] > target) {
                i--;
            } else {
                j++;
            }
        }

        return false;
    }
};