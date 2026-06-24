class Solution {
public:
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        const int R = mat.size(),
                  C = mat[0].size();

        int rl = 0, rr = R - 1;
        while (rl <= rr) {
            int rm = rl + ((rr - rl) >> 1);

            int maxValId = max_element(mat[rm].begin(), mat[rm].end()) - mat[rm].begin();
            int maxVal = mat[rm][maxValId];
            int topVal = (rm == 0) ? -1 : mat[rm - 1][maxValId]; 
            int bottomVal = (rm == R - 1) ? -1 : mat[rm + 1][maxValId]; 
            if (maxVal > topVal && maxVal > bottomVal) {
                return vector<int>{rm, maxValId};
            } else if (maxVal < bottomVal) {
                rl = rm + 1;
            } else {
                rr = rm - 1;
            }
        }

        return vector<int>{-1, -1};
    }
};